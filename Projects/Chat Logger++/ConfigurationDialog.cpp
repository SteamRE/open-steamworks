/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#include <wx/statline.h>
#include "ConfigurationDialog.h"
#include "Logger.h"
#include "App.h"
#include <wx/gbsizer.h>

enum
{
	wxID_LogDirPicker = 0,
	wxID_FilenameInput,
	wxID_ReplacementInput,
	wxID_MessageInput,
	wxID_EmoteInput,
	wxID_SeparationInput,
	wxID_DateInput,
	wxID_TimeInput,
};

BEGIN_EVENT_TABLE(CConfigurationDialog, wxDialog)
	EVT_TEXT(wxID_FilenameInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT(wxID_ReplacementInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT(wxID_MessageInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT(wxID_EmoteInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT(wxID_DateInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT(wxID_TimeInput, CConfigurationDialog::OnInputChange)
	EVT_TEXT_URL(wxID_ANY, CConfigurationDialog::OnTextURLEvent)
	EVT_BUTTON(wxID_ANY, CConfigurationDialog::OnButton)
END_EVENT_TABLE()

CConfigurationDialog::CConfigurationDialog() : wxDialog(NULL, wxID_ANY, wxString(_("Chat Logger++ - Configuration")), wxDefaultPosition, wxDefaultSize, wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxMINIMIZE_BOX | wxDIALOG_NO_PARENT), m_config(_T("Chat Logger++"), _T("OSW"))
{
	m_bEnablePreviews = false;

	m_pNotebook = new wxNotebook(this, wxID_ANY);

	m_pLoggingPanel = new wxPanel(m_pNotebook, wxID_ANY);
	m_pNotebook->AddPage(m_pLoggingPanel, _("Logging"));

	m_pHelpPanel = new wxPanel(m_pNotebook, wxID_ANY);
	m_pNotebook->AddPage(m_pHelpPanel, _("Help && Formatting"));
	{
		wxTextCtrl* pTextCtrl = new wxTextCtrl(m_pHelpPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH | wxTE_AUTO_URL | wxTE_READONLY);
		
		wxTextAttr originalAttr = pTextCtrl->GetDefaultStyle();
		wxTextAttr underlinedAttr = originalAttr;
		wxFont underlinedFont = pTextCtrl->GetDefaultStyle().GetFont();
		underlinedFont.SetUnderlined(true);
		underlinedAttr.SetFont(underlinedFont);

		pTextCtrl->SetDefaultStyle(underlinedAttr);
		pTextCtrl->AppendText(_("Common variables:\n\n"));
		pTextCtrl->SetDefaultStyle(originalAttr);

		pTextCtrl->AppendText
		(
			L"{Name}		- Sender's friend's name.\n"
			L"{Nickname}	- Sender's nickname, if it exists, otherwise their name.\n"
			L"{SteamID}	- Sender's SteamID.\n"
			L"{SteamID64}	- Sender's SteamID rendered as a 64bits integer.\n"
			L"\n"
			L"{MyName}	- Your current friend's name.\n"
			L"{MySteamID}	- Your SteamID.\n"
			L"{MySteamID64}	- Your SteamID rendered as a 64bits integer.\n"
			L"\n"
			L"{Date}		- Current date.\n"
			L"{Time}		- Current time.\n"
			L"{UnixTime}	- Seconds since unix epoch.\n"
			L"\n"
		);

		pTextCtrl->SetDefaultStyle(underlinedAttr);
		pTextCtrl->AppendText(_("Message specific variables:\n\n"));
		pTextCtrl->SetDefaultStyle(originalAttr);

		pTextCtrl->AppendText
		(
			L"{NewLine}	- New line character \"\\n\".\n"
			L"{Tab}		- Tab character \"\\t\".\n"
			L"\n"
			L"{Message}	- The actual chat message.\n"
			L"\n"
		);

		pTextCtrl->SetDefaultStyle(underlinedAttr);
		pTextCtrl->AppendText(_("Additional informations:\n\n"));
		pTextCtrl->SetDefaultStyle(originalAttr);

		pTextCtrl->AppendText
		(
			L"The format used for date and time is described here : http://www.cplusplus.com/reference/clibrary/ctime/strftime/ .\n"
			L"\n"
			L"This program is powered by Open Steamworks ( http://opensteamworks.org/ ).\n"
		);

		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);
		m_pHelpPanel->SetSizer(pBoxSizer);
		pBoxSizer->Add(pTextCtrl, 1, wxEXPAND);
	}

	wxBoxSizer *pBoxSizer = new wxBoxSizer(wxHORIZONTAL);
	m_pLoggingPanel->SetSizer(pBoxSizer);

	wxGridBagSizer *pGridBagSizer = new wxGridBagSizer(10, 10);
	pGridBagSizer->AddGrowableCol(0);
	pBoxSizer->Add(pGridBagSizer, 1, wxALL | wxEXPAND, 10);

	int iRow = 0;

	wxString logDirectory;
	m_config.Read(_T("LogDirectory"), &logDirectory, wxGetCwd());

	wxStaticText *pLogDirLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Log directory: "));
	m_pLogDirPicker = new wxDirPickerCtrl(m_pLoggingPanel, wxID_LogDirPicker, logDirectory);
	pGridBagSizer->Add(pLogDirLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);
	pGridBagSizer->Add(m_pLogDirPicker, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);

	{
		wxString filenameFormat;
		m_config.Read(_T("FilenameFormat"), &filenameFormat, _T("{SteamID} - {Nickname}.txt"));

		wxStaticText *pFilenameLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Filename format: "));
		pGridBagSizer->Add(pFilenameLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		m_pFilenameInput = new wxTextCtrl(pPanel, wxID_FilenameInput, filenameFormat);
		pBoxSizer->Add(m_pFilenameInput, 0, wxEXPAND);
		m_pFilenamePreviewLabel = new wxStaticText(pPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE);
		pBoxSizer->Add(m_pFilenamePreviewLabel, 1, wxEXPAND | wxALL, 5);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}

	wxString replacementChar;
	m_config.Read(_T("ReplacementChar"), &replacementChar, _T("_"));

	wxStaticText *pReplacementLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Invalid char replacement: "));
	m_pReplacementInput = new wxTextCtrl(m_pLoggingPanel, wxID_ReplacementInput, replacementChar);
	m_pReplacementInput->SetMaxLength(1);
	pGridBagSizer->Add(pReplacementLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);
	pGridBagSizer->Add(m_pReplacementInput, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);

	{
		wxStaticLine* pLine = new wxStaticLine(m_pLoggingPanel);
		pGridBagSizer->Add(pLine, wxGBPosition(iRow++, 0), wxGBSpan(1, 2), wxEXPAND);
	}

	{
		wxString messageFormat;
		m_config.Read(_T("MessageFormat"), &messageFormat, _T("[{Time}] {Name}: {Message}"));

		wxStaticText *pMessageLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Message format: "));
		pGridBagSizer->Add(pMessageLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		m_pMessageInput = new wxTextCtrl(pPanel, wxID_MessageInput, messageFormat);
		pBoxSizer->Add(m_pMessageInput, 0, wxEXPAND);
		m_pMessagePreviewLabel = new wxStaticText(pPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE);
		pBoxSizer->Add(m_pMessagePreviewLabel, 1, wxEXPAND | wxALL, 5);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}

	{
		wxString emoteFormat;
		m_config.Read(_T("EmoteFormat"), &emoteFormat, _T("[{Time}] * {Name} {Message}"));

		wxStaticText *pEmoteLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Emote format: "));
		pGridBagSizer->Add(pEmoteLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		m_pEmoteInput = new wxTextCtrl(pPanel, wxID_EmoteInput, emoteFormat);
		pBoxSizer->Add(m_pEmoteInput, 0, wxEXPAND);
		m_pEmotePreviewLabel = new wxStaticText(pPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE);
		pBoxSizer->Add(m_pEmotePreviewLabel, 1, wxEXPAND | wxALL, 5);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}

	{
		wxString separationString;
		m_config.Read(_T("SeparationString"), &separationString, _T("───────────────────"));

		wxStaticText *pSeparationLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Separation string: "));
		pGridBagSizer->Add(pSeparationLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		m_pSeparationInput = new wxTextCtrl(m_pLoggingPanel, wxID_SeparationInput, separationString);
		pGridBagSizer->Add(m_pSeparationInput, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}

	{
		wxStaticLine* pLine = new wxStaticLine(m_pLoggingPanel);
		pGridBagSizer->Add(pLine, wxGBPosition(iRow++, 0), wxGBSpan(1, 2), wxEXPAND);
	}

	{
		wxString dateFormat;
		m_config.Read(_T("DateFormat"), &dateFormat, _T("%x"));

		wxStaticText *pDateLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Date format: "));
		pGridBagSizer->Add(pDateLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		m_pDateInput = new wxTextCtrl(pPanel, wxID_DateInput, dateFormat);
		pBoxSizer->Add(m_pDateInput, 0, wxEXPAND);
		m_pDatePreviewLabel = new wxStaticText(pPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE);
		pBoxSizer->Add(m_pDatePreviewLabel, 1, wxEXPAND | wxALL, 5);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}

	{
		wxString timeFormat;
		m_config.Read(_T("TimeFormat"), &timeFormat, _T("%X"));

		wxStaticText *pTimeLabel = new wxStaticText(m_pLoggingPanel, wxID_ANY, _("Time format: "));
		pGridBagSizer->Add(pTimeLabel, wxGBPosition(iRow, 0), wxDefaultSpan, wxTOP, 3);

		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		m_pTimeInput = new wxTextCtrl(pPanel, wxID_TimeInput, timeFormat);
		pBoxSizer->Add(m_pTimeInput, 0, wxEXPAND);
		m_pTimePreviewLabel = new wxStaticText(pPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE);
		pBoxSizer->Add(m_pTimePreviewLabel, 1, wxEXPAND | wxALL, 5);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 1), wxDefaultSpan, wxEXPAND);
	}


	{
		wxStaticLine* pLine = new wxStaticLine(m_pLoggingPanel);
		pGridBagSizer->Add(pLine, wxGBPosition(iRow++, 0), wxGBSpan(1, 2), wxEXPAND);
	}

	{
		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxVERTICAL);

		bool bEnabled;
		m_config.Read(_T("Unstable"), &bEnabled, false);

		pUnstableCheckBox = new wxCheckBox(pPanel, wxID_ANY, _("Enable Group chat logging and Nickname support."));
		pUnstableCheckBox->SetValue(bEnabled);
		wxStaticText *pLabel = new wxStaticText(pPanel, wxID_ANY, _("These features are unstable and can break with any Steam update."));
		
		pBoxSizer->Add(pUnstableCheckBox);
		pBoxSizer->Add(pLabel, 0, wxLEFT, 17);
		pPanel->SetSizer(pBoxSizer);
		
		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 0), wxGBSpan(1, 2));
	}

	{
		wxPanel* pPanel = new wxPanel(m_pLoggingPanel);
		wxBoxSizer *pBoxSizer = new wxBoxSizer(wxHORIZONTAL);
		wxButton* pOKButton = new wxButton(pPanel, wxID_OK);
		pBoxSizer->Add(pOKButton);
		wxButton* pCancelButton = new wxButton(pPanel, wxID_CANCEL);
		pBoxSizer->Add(pCancelButton);
		pPanel->SetSizer(pBoxSizer);

		pGridBagSizer->Add(pPanel, wxGBPosition(iRow++, 0), wxGBSpan(1, 2), wxALIGN_RIGHT);
	}

	m_bEnablePreviews = true;

	UpdatePreviews();

	m_pNotebook->Fit();
	this->Fit();
}

void CConfigurationDialog::UpdatePreviews()
{
	if(!m_bEnablePreviews)
		return;

	CSteamID friendSteamID(1234, k_EUniversePublic, k_EAccountTypeIndividual);
	CSteamID mySteamID(1337, k_EUniversePublic, k_EAccountTypeIndividual);

	{
		wxString preview = m_pFilenameInput->GetValue();
		wxArrayString tags, replacements;

		tags.Add(_T("{SteamID}"));		replacements.Add(wxString(friendSteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{MySteamID}"));	replacements.Add(wxString(mySteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{SteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), friendSteamID.ConvertToUint64()));
		tags.Add(_T("{MySteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), mySteamID.ConvertToUint64()));
		tags.Add(_T("{Name}"));			replacements.Add(_("Christopher"));
		tags.Add(_T("{Nickname}"));		replacements.Add(_("Chris"));
		tags.Add(_T("{MyName}"));		replacements.Add(_("Your Name"));
		tags.Add(_T("{Date}"));			replacements.Add(wxDateTime::Now().Format(m_pDateInput->GetValue()));
		tags.Add(_T("{Time}"));			replacements.Add(wxDateTime::Now().Format(m_pTimeInput->GetValue()));
		tags.Add(_T("{UnixTime}"));		replacements.Add(wxString::Format(_T("%lld"), (long long)wxDateTime::GetTimeNow()));

		preview = CLogger::TagsReplace(preview, tags, replacements);
		static const wxChar* invalidChars[] = {_T("\\"), _T("/"), _T(":"), _T("*"), _T("?"), _T("\""), _T("<"), _T(">"), _T("|")};

		for(int i = 0; i < sizeof(invalidChars) / sizeof(*invalidChars); i++)
		{
			preview.Replace(invalidChars[i], m_pReplacementInput->GetValue());
		}

		m_pFilenamePreviewLabel->SetLabel(wxString::Format(_("Preview: %s"), preview));
	}

	{
		wxString preview = m_pMessageInput->GetValue();
		wxArrayString tags, replacements;

		tags.Add(_T("{SteamID}"));		replacements.Add(wxString(friendSteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{MySteamID}"));	replacements.Add(wxString(mySteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{SteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), friendSteamID.ConvertToUint64()));
		tags.Add(_T("{MySteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), mySteamID.ConvertToUint64()));
		tags.Add(_T("{Name}"));			replacements.Add(_("Christopher"));
		tags.Add(_T("{Nickname}"));		replacements.Add(_("Chris"));
		tags.Add(_T("{MyName}"));		replacements.Add(_("Your Name"));
		tags.Add(_T("{Date}"));			replacements.Add(wxDateTime::Now().Format(m_pDateInput->GetValue()));
		tags.Add(_T("{Time}"));			replacements.Add(wxDateTime::Now().Format(m_pTimeInput->GetValue()));
		tags.Add(_T("{UnixTime}"));		replacements.Add(wxString::Format(_T("%lld"), (long long)wxDateTime::GetTimeNow()));
		tags.Add(_T("{NewLine}"));		replacements.Add(_T("\n"));
		tags.Add(_T("{Tab}"));			replacements.Add(_T("\t"));
		tags.Add(_T("{Message}"));		replacements.Add(_("Hello there!"));

		preview = CLogger::TagsReplace(preview, tags, replacements);

		m_pMessagePreviewLabel->SetLabel(wxString::Format(_("Preview: %s"), preview));
	}

	{
		wxString preview = m_pEmoteInput->GetValue();
		wxArrayString tags, replacements;

		tags.Add(_T("{SteamID}"));		replacements.Add(wxString(friendSteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{MySteamID}"));	replacements.Add(wxString(mySteamID.SteamRender(), wxConvUTF8));
		tags.Add(_T("{SteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), friendSteamID.ConvertToUint64()));
		tags.Add(_T("{MySteamID64}"));	replacements.Add(wxString::Format(_T("%llu"), mySteamID.ConvertToUint64()));
		tags.Add(_T("{Name}"));			replacements.Add(_("Christopher"));
		tags.Add(_T("{Nickname}"));		replacements.Add(_("Chris"));
		tags.Add(_T("{MyName}"));		replacements.Add(_("Your Name"));
		tags.Add(_T("{Date}"));			replacements.Add(wxDateTime::Now().Format(m_pDateInput->GetValue()));
		tags.Add(_T("{Time}"));			replacements.Add(wxDateTime::Now().Format(m_pTimeInput->GetValue()));
		tags.Add(_T("{UnixTime}"));		replacements.Add(wxString::Format(_T("%lld"), (long long)wxDateTime::GetTimeNow()));
		tags.Add(_T("{NewLine}"));		replacements.Add(_T("\n"));
		tags.Add(_T("{Tab}"));			replacements.Add(_T("\t"));
		tags.Add(_T("{Message}"));		replacements.Add(_("does an emote."));

		preview = CLogger::TagsReplace(preview, tags, replacements);

		m_pEmotePreviewLabel->SetLabel(wxString::Format(_("Preview: %s"), preview));
	}

	m_pDatePreviewLabel->SetLabel(wxString::Format(_("Preview: %s"), wxDateTime::Now().Format(m_pDateInput->GetValue())));
	m_pTimePreviewLabel->SetLabel(wxString::Format(_("Preview: %s"), wxDateTime::Now().Format(m_pTimeInput->GetValue())));

	m_pFilenamePreviewLabel->Wrap(300);
	m_pMessagePreviewLabel->Wrap(300);
	m_pEmotePreviewLabel->Wrap(300);
	m_pDatePreviewLabel->Wrap(300);
	m_pTimePreviewLabel->Wrap(300);

	m_pNotebook->Fit();
	this->Fit();
}

void CConfigurationDialog::OnInputChange(wxCommandEvent& event)
{
	UpdatePreviews();
}

void CConfigurationDialog::OnTextURLEvent(wxTextUrlEvent& event)
{
	if(event.GetMouseEvent().LeftIsDown())
	{
		wxTextCtrl* pTextCtrl = (wxTextCtrl*)event.GetEventObject();
		wxLaunchDefaultBrowser(pTextCtrl->GetRange(event.GetURLStart(), event.GetURLEnd()));
	}
}

void CConfigurationDialog::OnButton(wxCommandEvent& event)
{
	if(event.GetId() == GetAffirmativeId())
	{
		m_config.Write(_T("LogDirectory"), m_pLogDirPicker->GetPath());
		m_config.Write(_T("FilenameFormat"), m_pFilenameInput->GetValue());
		m_config.Write(_T("ReplacementChar"), m_pReplacementInput->GetValue());
		m_config.Write(_T("MessageFormat"), m_pMessageInput->GetValue());
		m_config.Write(_T("EmoteFormat"), m_pEmoteInput->GetValue());
		m_config.Write(_T("SeparationString"), m_pSeparationInput->GetValue());
		m_config.Write(_T("DateFormat"), m_pDateInput->GetValue());
		m_config.Write(_T("TimeFormat"), m_pTimeInput->GetValue());
		m_config.Write(_T("Unstable"), pUnstableCheckBox->IsChecked());

		CLogger* pLogger = wxGetApp().GetLogger();
		pLogger->SetLogDirectory(m_pLogDirPicker->GetPath());
		pLogger->SetFilenameFormat(m_pFilenameInput->GetValue());
		pLogger->SetReplacementChar(m_pReplacementInput->GetValue()[0]);
		pLogger->SetMessageFormat(m_pMessageInput->GetValue());
		pLogger->SetEmoteFormat(m_pEmoteInput->GetValue());
		pLogger->SetSeparationString(m_pSeparationInput->GetValue());
		pLogger->SetDateFormat(m_pDateInput->GetValue());
		pLogger->SetTimeFormat(m_pTimeInput->GetValue());
		pLogger->UseClientInterfaces(pUnstableCheckBox->IsChecked());
	}

	this->Close();
}