/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#include <wx/wx.h>
#include <wx/msw/regconf.h>
#include "SigScanner.h"
#include "Logger.h"
#include "App.h"

CLogger::CLogger() : wxThread(wxTHREAD_DETACHED), m_steamLoader(CSteamAPILoader::k_ESearchOrderSteamInstallFirst)
{
	m_hPipe = 0;
	m_hUser = 0;
	m_pSteamClient = NULL;
	m_pSteamFriends = NULL;
	m_pClientFriends = NULL;
	m_pSteamUser = NULL;

	m_pGetChatRoomEntry = NULL;
	m_pGetChatRoomName = NULL;
	m_pGetPlayerNickname = NULL;

	wxRegConfig config(_T("Chat Logger++"), _T("OSW"));
	config.Read(_T("LogDirectory"), &m_logDirectory, wxGetCwd());
	config.Read(_T("FilenameFormat"), &m_filenameFormat, _T("{SteamID} - {Nickname}.txt"));
	config.Read(_T("ReplacementChar"), &m_replacementChar, _T("_"));
	config.Read(_T("MessageFormat"), &m_messageFormat, _T("[{Time}] {Name}: {Message}"));
	config.Read(_T("EmoteFormat"), &m_emoteFormat, _T("[{Time}] * {Name} {Message}"));
	config.Read(_T("DateFormat"), &m_dateFormat, _T("%x"));
	config.Read(_T("TimeFormat"), &m_timeFormat, _T("%X"));
	config.Read(_T("SeparationString"), &m_separationString, _T("───────────────────"));
	config.Read(_T("Unstable"), &m_bUseClientInterfaces, false);

	this->Create();
	this->Run();
}

CLogger::~CLogger()
{
	CloseLogs();
	CleanupSteam();
}

void CLogger::SetLogDirectory(const wxString& path)
{
	wxMutexLocker configLock(m_configLock);

	m_logDirectory = path;
}

void CLogger::SetFilenameFormat(const wxString& format)
{
	wxMutexLocker configLock(m_configLock);

	m_filenameFormat = format;
}

void CLogger::SetReplacementChar(const wxString& c)
{
	wxMutexLocker configLock(m_configLock);

	m_replacementChar = c;
}

void CLogger::SetMessageFormat(const wxString& format)
{
	wxMutexLocker configLock(m_configLock);

	m_messageFormat = format;
}

void CLogger::SetEmoteFormat(const wxString& format)
{
	wxMutexLocker configLock(m_configLock);

	m_emoteFormat = format;
}

void CLogger::SetSeparationString(const wxString& string)
{
	wxMutexLocker configLock(m_configLock);

	m_separationString = string;
}

void CLogger::SetDateFormat(const wxString& format)
{
	wxMutexLocker configLock(m_configLock);

	m_dateFormat = format;
}

void CLogger::SetTimeFormat(const wxString& format)
{
	wxMutexLocker configLock(m_configLock);

	m_timeFormat = format;
}

void* CLogger::FindSteamFunction(const char* cszName)
{
	static CSigScanner sigScanner(GetModuleHandleA("steamclient.dll"));

	for(unsigned char* pMatch = NULL; pMatch = (unsigned char*)sigScanner.FindSignature("\x68\x00\x00\x00\x00\x51\x8d\x55\xd0\x52\x50\xe8\x00\x00\x00\x00\x8d\x48\x04\xe8\x00\x00\x00\x00\x8b\xf0\x8b\xce\xe8\x00\x00\x00\x00\x3c\x01\x74\x00", "x????xxx?xxx????xxxx????xxxxx????xxx?", false, pMatch); )
	{
		const char* cszFunctionName = *(const char**)(pMatch + 1);
		if(strcmp(cszFunctionName, cszName) == 0)
		{
			return sigScanner.FindSignature("\x55\x8B\xEC\x83\xEC", "xxxxx", true, pMatch);
		}
	}

	return NULL;
}

bool CLogger::InitSteam()
{
	CreateInterfaceFn steam3Factory = m_steamLoader.GetSteam3Factory();
	if(!steam3Factory)
		return false;

	m_pSteamClient = (ISteamClient012*)steam3Factory(STEAMCLIENT_INTERFACE_VERSION_012, NULL);
	if(!m_pSteamClient)
		return false;

	m_hPipe = m_pSteamClient->CreateSteamPipe();
	if(!m_hPipe || m_hPipe == -1)
		return false;

	// Steamworks likes to deadlock if we create the pipe while Steam is starting
	// Which leads us to use this ugly hack.
	m_pSteamClient->BReleaseSteamPipe(m_hPipe);
	wxMilliSleep(5000);

	m_hPipe = m_pSteamClient->CreateSteamPipe();
	if(!m_hPipe || m_hPipe == -1)
		return false;

	m_hUser = m_pSteamClient->ConnectToGlobalUser(m_hPipe);
	if(!m_hUser)
		return false;

	m_pSteamFriends = (ISteamFriends013*)m_pSteamClient->GetISteamFriends(m_hUser, m_hPipe, STEAMFRIENDS_INTERFACE_VERSION_013);
	if(!m_pSteamFriends)
		return false;

	m_pSteamUser = (ISteamUser016*)m_pSteamClient->GetISteamUser(m_hUser, m_hPipe, STEAMUSER_INTERFACE_VERSION_016);
	if(!m_pSteamUser)
		return false;

	wxGetApp().SetTrayIcon(CApp::k_EIconNormal);
	wxGetApp().Message(_("Connected to Steam."));

	if(m_bUseClientInterfaces)
	{
		IClientEngine* pClientEngine = (IClientEngine*)steam3Factory(CLIENTENGINE_INTERFACE_VERSION, NULL);
		if(!pClientEngine)
		{
			wxGetApp().SetTrayIcon(CApp::k_EIconWarning, _("Group chat logging and Nickname support are disabled"));
			wxGetApp().Warning(_("Unable to get IClientEngine interface,\nGroup chat logging and Nickname support are disabled."));
			return true;
		}

		m_pClientFriends = pClientEngine->GetIClientFriends(m_hUser, m_hPipe, CLIENTFRIENDS_INTERFACE_VERSION);
		if(!m_pClientFriends)
		{
			wxGetApp().SetTrayIcon(CApp::k_EIconWarning, _("Group chat logging and Nickname support are disabled"));
			wxGetApp().Warning(_("Unable to get IClientFriends interface,\nGroup chat logging and Nickname support are disabled."));
			return true;
		}

		m_pGetChatRoomEntry = (int32 (__thiscall *)(IClientFriends *,CSteamID, int32, CSteamID *, void *, int32, EChatEntryType *)) FindSteamFunction("GetChatRoomEntry");
		if(!m_pGetChatRoomEntry)
		{
			wxGetApp().SetTrayIcon(CApp::k_EIconWarning, _("Group chat logging is disabled"));
			wxGetApp().Warning(_("Unable to find GetChatRoomEntry,\nGroup chat logging is disabled."));
		}
		
		m_pGetChatRoomName = (const char *(__thiscall *)(IClientFriends *, CSteamID)) FindSteamFunction("GetChatRoomName");
		if(!m_pGetChatRoomName)
		{
			wxGetApp().SetTrayIcon(CApp::k_EIconWarning, _("{Name} variable is disabled"));
			wxGetApp().Warning(_("Unable to find GetChatRoomName,\nThe {Name} variable won't work for chat rooms."));
		}
		
		m_pGetPlayerNickname = (const char *(__thiscall *)(IClientFriends *, CSteamID)) FindSteamFunction("GetPlayerNickname");
		if(!m_pGetPlayerNickname)
		{
			wxGetApp().SetTrayIcon(CApp::k_EIconWarning, _("Nickname support is disabled"));
			wxGetApp().Warning(_("Unable to find GetPlayerNickname,\nNickname support is disabled."));
		}
	}

	return true;
}

void CLogger::CleanupSteam()
{
	if(m_pSteamClient)
	{
		if(m_hPipe && m_hPipe != -1)
		{
			if(m_hUser)
			{
				m_pSteamClient->ReleaseUser(m_hPipe, m_hUser);
			}
			m_pSteamClient->BReleaseSteamPipe(m_hPipe);
		}
	}

	m_hPipe = 0;
	m_hUser = 0;
	m_pSteamClient = NULL;
	m_pSteamFriends = NULL;
	m_pClientFriends = NULL;
	m_pSteamUser = NULL;

	m_pGetChatRoomEntry = NULL;
	m_pGetChatRoomName = NULL;
	m_pGetPlayerNickname = NULL;
}

void CLogger::UseClientInterfaces(bool bUse)
{
	if(m_bUseClientInterfaces != bUse)
	{
		wxGetApp().Message(_("Reloading..."));

		wxMutexLocker steamLock(m_steamLock);

		CloseLogs();
		m_bUseClientInterfaces = bUse;
		CleanupSteam();
	}
}

void CLogger::CallbackHandlerThread()
{
	for(; !this->TestDestroy(); this->Sleep(100))
	{
		wxMutexLocker steamLock(m_steamLock);

		if(!m_hPipe || m_hPipe == -1)
		{
			if(!InitSteam())
				continue;
		}

		static unsigned int i = 0;
		if(++i % 50 == 0)
		{
			// This dummy call will trigger the IPCFailure_t callback if Steam has been closed.
			if(m_pSteamUser)
				m_pSteamUser->BLoggedOn();
		}

		CallbackMsg_t callbackMsg;
		while(Steam_BGetCallback(m_hPipe, &callbackMsg))
		{
			switch(callbackMsg.m_iCallback)
			{
			case IPCFailure_t::k_iCallback:
				{
					IPCFailure_t* pIPCFailure = (IPCFailure_t*)callbackMsg.m_pubParam;
					OnIPCFailure(pIPCFailure);
					break;
				}
			case FriendChatMsg_t::k_iCallback:
				{
					FriendChatMsg_t* pFriendChatMsg = (FriendChatMsg_t*)callbackMsg.m_pubParam;
					OnFriendChatMsg(pFriendChatMsg);
					break;
				}
			case ChatRoomMsg_t::k_iCallback:
				{
					ChatRoomMsg_t* pChatRoomMsg = (ChatRoomMsg_t*)callbackMsg.m_pubParam;
					OnChatRoomMsg(pChatRoomMsg);
					break;
				}
			case ChatRoomDlgClose_t::k_iCallback:
				{
					ChatRoomDlgClose_t* pChatRoomDlgClose = (ChatRoomDlgClose_t*)callbackMsg.m_pubParam;
					OnChatRoomDlgClose(pChatRoomDlgClose);
					break;
				}
			}
			Steam_FreeLastCallback(m_hPipe);
		}
	}
}

void CLogger::OnIPCFailure(IPCFailure_t* pIPCFailure)
{
	m_hPipe = 0;
	m_hUser = 0;
	m_pSteamClient = NULL;
	m_pSteamFriends = NULL;
	m_pSteamUser = NULL;

	m_pGetChatRoomEntry = NULL;
	m_pGetChatRoomName = NULL;
	m_pGetPlayerNickname = NULL;

	CloseLogs();

	wxGetApp().SetTrayIcon(CApp::k_EIconDisconnected, _("Connection to Steam lost"));
	wxGetApp().Warning(_("Connection to Steam lost."));
}

void CLogger::OnFriendChatMsg(FriendChatMsg_t* pFriendChatMsg)
{
	if(!m_pSteamFriends)
		return;

	char szMessage[k_cchFriendChatMsgMax + 1];
	EChatEntryType eEntryType;
	int iMessageSize = m_pSteamFriends->GetFriendMessage(pFriendChatMsg->m_ulFriendID, pFriendChatMsg->m_iChatID, szMessage, sizeof(szMessage) - 1, &eEntryType);
	szMessage[iMessageSize] = '\0';

	if(iMessageSize)
	{
		if(eEntryType == k_EChatEntryTypeChatMsg)
		{
			wxFFile* pFile = GetLogFile(pFriendChatMsg->m_ulFriendID);
			if(pFile)
			{
				wxString message = m_messageFormat + _T("\n");
				FormatMessage(message, pFriendChatMsg->m_ulSenderID, szMessage);
				pFile->Write(message);
				pFile->Flush();
			}
		}
		else if(eEntryType == k_EChatEntryTypeEmote)
		{
			wxFFile* pFile = GetLogFile(pFriendChatMsg->m_ulFriendID);
			if(pFile)
			{
				wxString message = m_emoteFormat + _T("\n");
				FormatMessage(message, pFriendChatMsg->m_ulSenderID, szMessage);
				pFile->Write(message);
				pFile->Flush();
			}
		}
	}
}

void CLogger::OnChatRoomMsg(ChatRoomMsg_t* pChatRoomMsg)
{
	if(!m_pClientFriends || !m_pGetChatRoomEntry)
		return;

	char szMessage[k_cchFriendChatMsgMax + 1];
	EChatEntryType eEntryType;
	CSteamID chatterID;
	int iMessageSize = m_pGetChatRoomEntry(m_pClientFriends, pChatRoomMsg->m_ulSteamIDChat, pChatRoomMsg->m_iChatID, &chatterID, szMessage, sizeof(szMessage) - 1, &eEntryType);
	szMessage[iMessageSize] = '\0';

	if(iMessageSize)
	{
		if(eEntryType == k_EChatEntryTypeChatMsg)
		{
			wxFFile* pFile = GetLogFile(pChatRoomMsg->m_ulSteamIDChat);
			if(pFile)
			{
				wxString message = m_messageFormat + _T("\n");
				FormatMessage(message, pChatRoomMsg->m_ulSteamIDUser, szMessage);
				pFile->Write(message);
				pFile->Flush();
			}
		}
		else if(eEntryType == k_EChatEntryTypeEmote)
		{
			wxFFile* pFile = GetLogFile(pChatRoomMsg->m_ulSteamIDChat);
			if(pFile)
			{
				wxString message = m_emoteFormat + _T("\n");
				FormatMessage(message, pChatRoomMsg->m_ulSteamIDUser, szMessage);
				pFile->Write(message);
				pFile->Flush();
			}
		}
	}
}

void CLogger::OnChatRoomDlgClose(ChatRoomDlgClose_t* pChatRoomDlgClose)
{
	wxFFile* pFile = GetLogFile(pChatRoomDlgClose->m_ulSteamIDChat, false);
	if(pFile)
	{
		pFile->Write(m_separationString);
		pFile->Write(_T("\n"));

		pFile->Flush();
		pFile->Close();
		delete pFile;

		m_logsOpened.erase(pChatRoomDlgClose->m_ulSteamIDChat);
	}
}


wxString CLogger::TagsReplace(const wxString& string, const wxArrayString& tags, const wxArrayString& replacements)
{
	wxString ret;
	for(size_t i = 0; i < string.length(); )
	{
		bool bFound = false;

		if(string[i] == '{')
		{
			for(size_t j = 0; j < tags.Count(); j++)
			{
				const wxString& tag = tags[j];
				if(string.substr(i, tag.length()) == tag)
				{
					ret += replacements[j];
					i += tag.length();

					bFound = true;
					break;
				}
			}
		}

		if(!bFound)
		{
			ret += string[i++];
		}
	}

	return ret;
}

void CLogger::FormatFilename(wxString& string, CSteamID steamID)
{
	wxMutexLocker configLock(m_configLock);

	wxArrayString tags, replacements;

	tags.Add(_T("{SteamID}"));		replacements.Add(wxString(steamID.SteamRender(), wxConvUTF8));
	tags.Add(_T("{MySteamID}"));	replacements.Add(wxString(m_pSteamUser->GetSteamID().SteamRender(), wxConvUTF8));
	tags.Add(_T("{SteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), steamID.ConvertToUint64()));
	tags.Add(_T("{MySteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), m_pSteamUser->GetSteamID().ConvertToUint64()));

	tags.Add(_T("{Name}"));
	if(steamID.BIndividualAccount())
	{
		replacements.Add(wxString(m_pSteamFriends->GetFriendPersonaName(steamID), wxConvUTF8));
	}
	else
	{
		const char* cszChatRoomName = NULL;
		
		if(m_pClientFriends && m_pGetChatRoomName)
			cszChatRoomName = m_pGetChatRoomName(m_pClientFriends, steamID);

		if(*cszChatRoomName)
		{
			replacements.Add(wxString(cszChatRoomName, wxConvUTF8));
		}
		else
		{
			wxString name;
			for(int i = 0; i < m_pSteamFriends->GetFriendCountFromSource(steamID); i++)
			{
				name += wxString(m_pSteamFriends->GetFriendPersonaName(m_pSteamFriends->GetFriendFromSourceByIndex(steamID, i)), wxConvUTF8) + _T(" + ");
			}
			name.RemoveLast(3);

			replacements.Add(name);
		}
	}

	tags.Add(_T("{Nickname}"));

	if(steamID.BIndividualAccount())
	{
		const char* cszNickname = NULL;

		if(m_pClientFriends && m_pGetPlayerNickname)
			cszNickname = m_pGetPlayerNickname(m_pClientFriends, steamID);

		if(cszNickname)
		{
			replacements.Add(wxString(cszNickname, wxConvUTF8));
		}
		else
		{
			replacements.Add(wxString(m_pSteamFriends->GetFriendPersonaName(steamID), wxConvUTF8));
		}
	}
	else
	{
		replacements.Add(replacements.Last());
	}

	tags.Add(_T("{MyName}"));		replacements.Add(wxString(m_pSteamFriends->GetPersonaName(), wxConvUTF8));
	tags.Add(_T("{Date}"));			replacements.Add(wxDateTime::Now().Format(m_dateFormat));
	tags.Add(_T("{Time}"));			replacements.Add(wxDateTime::Now().Format(m_timeFormat));
	tags.Add(_T("{UnixTime}"));		replacements.Add(wxString::Format(_T("%lld"), (long long)wxDateTime::GetTimeNow()));
	
	string = TagsReplace(string, tags, replacements);

	static const wxChar* invalidChars[] = {_T("\\"), _T("/"), _T(":"), _T("*"), _T("?"), _T("\""), _T("<"), _T(">"), _T("|")};
	for(int i = 0; i < sizeof(invalidChars) / sizeof(*invalidChars); i++)
	{
		string.Replace(invalidChars[i], m_replacementChar);
	}
}

void CLogger::FormatMessage(wxString& string, CSteamID steamID, const char* cszMessage)
{
	wxMutexLocker configLock(m_configLock);

	wxArrayString tags, replacements;

	tags.Add(_T("{SteamID}"));		replacements.Add(wxString(steamID.SteamRender(), wxConvUTF8));
	tags.Add(_T("{MySteamID}"));	replacements.Add(wxString(m_pSteamUser->GetSteamID().SteamRender(), wxConvUTF8));
	tags.Add(_T("{SteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), steamID.ConvertToUint64()));
	tags.Add(_T("{MySteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), m_pSteamUser->GetSteamID().ConvertToUint64()));

	tags.Add(_T("{Name}"));

	wxString name = wxString(m_pSteamFriends->GetFriendPersonaName(steamID), wxConvUTF8);
	const char* cszNickname = NULL;

	if(m_pClientFriends && m_pGetPlayerNickname)
		cszNickname = m_pGetPlayerNickname(m_pClientFriends, steamID);

	if(cszNickname)
	{
		name += _T(" (") + wxString(cszNickname, wxConvUTF8) + _T(")");
	}
	replacements.Add(name);

	tags.Add(_T("{MyName}"));		replacements.Add(wxString(m_pSteamFriends->GetPersonaName(), wxConvUTF8));
	tags.Add(_T("{Date}"));			replacements.Add(wxDateTime::Now().Format(m_dateFormat));
	tags.Add(_T("{Time}"));			replacements.Add(wxDateTime::Now().Format(m_timeFormat));
	tags.Add(_T("{UnixTime}"));		replacements.Add(wxString::Format(_T("%lld"), (long long)wxDateTime::GetTimeNow()));
	tags.Add(_T("{NewLine}"));		replacements.Add(_T("\n"));
	tags.Add(_T("{Tab}"));			replacements.Add(_T("\t"));
	tags.Add(_T("{Message}"));		replacements.Add(wxString(cszMessage, wxConvUTF8));
	
	string = TagsReplace(string, tags, replacements);
}

wxFFile* CLogger::GetLogFile(CSteamID steamID, bool bOpenIfNeeded)
{
	std::map<CSteamID, wxFFile*>::iterator it = m_logsOpened.find(steamID);
	if(it != m_logsOpened.end())
		return it->second;

	if(!bOpenIfNeeded)
		return NULL;

	wxString filename = m_filenameFormat;
	FormatFilename(filename, steamID);

	wxLogNull logNull;

	wxFFile* pFile = new wxFFile(m_logDirectory + _T("/") + filename, _T("at"));

	if(pFile->IsOpened())
	{
		m_logsOpened[steamID] = pFile;

		if(!pFile->Length())
		{
			// Add the UTF-8 BOM
			pFile->Write("\xEF\xBB\xBF", 3);
		}
	}
	else
	{
		wxGetApp().Warning(wxString::Format(_("Unable to open '%s' !"), filename));
		delete pFile;
		pFile = NULL;
	}

	return pFile;
}

void CLogger::CloseLogs()
{
	for(std::map<CSteamID, wxFFile*>::iterator it = m_logsOpened.begin(); it != m_logsOpened.end(); )
	{
		it->second->Write(m_separationString);
		it->second->Write(_T("\n"));

		it->second->Flush();
		it->second->Close();
		delete it->second;

		m_logsOpened.erase(it++);
	}
}

CLogger::ExitCode CLogger::Entry()
{
	CallbackHandlerThread();

	return NULL;
}