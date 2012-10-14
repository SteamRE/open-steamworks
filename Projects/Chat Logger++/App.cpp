/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#include <wx/stdpaths.h>
#include <wx/snglinst.h>

#include "App.h"

#include "TaskBarIcon.h"
#include "ConfigurationDialog.h"
#include "Logger.h"

enum
{
	wxID_AUTOSTART = 1,
};

BEGIN_EVENT_TABLE(CApp, wxApp)
	EVT_TASKBAR_LEFT_DCLICK(OnTaskBarIconClick)
	EVT_TASKBAR_RIGHT_DOWN(OnTaskBarIconClick)
	EVT_MENU(wxID_AUTOSTART, OnAutoStartButtonClick)
	EVT_MENU(wxID_OPEN, OnConfigurationButtonClick)
	EVT_MENU(wxID_EXIT, OnExitButtonClick)
END_EVENT_TABLE()

IMPLEMENT_APP(CApp)


CApp::CApp()
{
	m_pConfigurationDialog = NULL;
	m_pTaskBarIcon = NULL;
	m_pLogger = NULL;
}

void CApp::InvalidParameterHandler(const wchar_t * expression, const wchar_t * function, const wchar_t * file, unsigned int line, uintptr_t pReserved)
{
}

bool CApp::OnInit()
{
	static wxSingleInstanceChecker checker(wxString::Format(_T("Chat Logger++ - %s"), wxGetUserId()));
	if(checker.IsAnotherRunning())
	{
		wxMessageBox(_("Chat Logger++ is already running."), _("Chat Logger++"), wxOK | wxCENTRE | wxICON_EXCLAMATION);
		return false;
	}

	_set_invalid_parameter_handler(&InvalidParameterHandler);
	setlocale(LC_TIME, "");

	m_pTaskBarIcon = new CTaskBarIcon();
	this->SetTrayIcon(k_EIconDisconnected, _("Not connected to Steam"));

	m_pLogger = new CLogger();

	return true;
}

void CApp::CleanUp()
{
	if(m_pLogger)
	{
		m_pLogger->Delete();
		//delete m_pLogger;
	}

	if(m_pTaskBarIcon)
	{
		m_pTaskBarIcon->RemoveIcon();
		delete m_pTaskBarIcon;
	}

	if(m_pConfigurationDialog)
		m_pConfigurationDialog->Destroy();
}

void CApp::OnTaskBarIconClick(wxTaskBarIconEvent& event)
{
	bool bAutoRun = false;

	HKEY hkRegistry;
	if(RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, KEY_QUERY_VALUE, &hkRegistry) == ERROR_SUCCESS)
	{
		wchar_t wszPath[4096];
		memset(wszPath, 0, sizeof(wszPath));
		DWORD dwType, dwSize = sizeof(wszPath) - 1;
		if(RegQueryValueExW(hkRegistry, L"Chat Logger++", 0, &dwType, (unsigned char *)wszPath, &dwSize) == ERROR_SUCCESS)
		{
			if(wxString(wxStandardPaths::Get().GetExecutablePath()).CmpNoCase(wszPath) == 0)
				bAutoRun = true;
		}
		RegCloseKey(hkRegistry);
	}

	wxMenu menu;
	menu.Append(wxID_OPEN, _("Configuration"));
	menu.AppendSeparator();
	menu.Append(wxID_AUTOSTART, _("Start with Windows"), wxEmptyString, wxITEM_CHECK)->Check(bAutoRun);
	menu.AppendSeparator();
	menu.Append(wxID_EXIT);

	m_pTaskBarIcon->PopupMenu(&menu);

	event.Skip();
}

void CApp::OnExitButtonClick(wxCommandEvent& event)
{
	this->ExitMainLoop();
}

void CApp::OnAutoStartButtonClick(wxCommandEvent& event)
{
	HKEY hkRegistry;
	if(RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, KEY_WRITE, &hkRegistry) == ERROR_SUCCESS)
	{
		if(event.IsChecked())
		{
			wxString appPath = wxStandardPaths::Get().GetExecutablePath();
			RegSetValueExW(hkRegistry, L"Chat Logger++", 0, REG_SZ, (BYTE*)appPath.wc_str(), (wcslen(appPath.wc_str()) + 1) * sizeof(wchar_t));
		}
		else
		{
			RegDeleteValueA(hkRegistry, "Chat Logger++");
		}
		RegCloseKey(hkRegistry);
	}
}

void CApp::OnConfigurationWindowClosed(wxCloseEvent& event)
{
	m_pConfigurationDialog->Destroy();
	m_pConfigurationDialog = NULL;
}

void CApp::OnConfigurationButtonClick(wxCommandEvent& event)
{
	if(!m_pConfigurationDialog)
	{
		m_pConfigurationDialog = new CConfigurationDialog();
		m_pConfigurationDialog->Connect(wxEVT_CLOSE_WINDOW, (wxObjectEventFunction)&CApp::OnConfigurationWindowClosed, NULL, this);
	}

	m_pConfigurationDialog->Show();

	if(m_pConfigurationDialog)
		m_pConfigurationDialog->Raise();
}

void CApp::Message(const wxString& message)
{
	m_pTaskBarIcon->ShowMessage(_T(""), message, CTaskBarIcon::k_EIconInfo);
}

void CApp::Warning(const wxString& message)
{
	m_pTaskBarIcon->ShowMessage(_T(""), message, CTaskBarIcon::k_EIconWarning);
}

void CApp::SetTrayIcon(EIcon eIcon, const wxString& text/* = _T("")*/)
{
	wxString str;
	if(text.Len())
	{
		str.Printf(_("Chat Logger++\n%s"), text);
	}
	else
	{
		str = _("Chat Logger++");
	}

	wxIcon icon;

	switch(eIcon)
	{
	case k_EIconDisconnected:
		{
			icon = wxICON(3_AppDisconnectedIcon);
			break;
		}
	case k_EIconWarning:
		{
			icon = wxICON(2_AppWarningIcon);
			break;
		}
	case k_EIconNormal:
	default:
		{
			icon = wxICON(1_AppIcon);
			break;
		}
	}
	
	m_pTaskBarIcon->SetIcon(icon, str);
}

CLogger* CApp::GetLogger()
{
	return m_pLogger;
}