/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#include <wx/stdpaths.h>
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
	_set_invalid_parameter_handler(&InvalidParameterHandler);
	setlocale(LC_TIME, "");

	m_pTaskBarIcon = new CTaskBarIcon();
	m_pTaskBarIcon->SetIcon(wxICON(AppIcon), L"Chat Logger++");

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
	menu.Append(wxID_OPEN, L"Configuration");
	menu.AppendSeparator();
	menu.Append(wxID_AUTOSTART, L"Start with Windows", wxEmptyString, wxITEM_CHECK)->Check(bAutoRun);
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
			RegSetValueExW(hkRegistry, L"Chat Logger++", 0, REG_SZ, (BYTE*)appPath.c_str(), (wcslen(appPath.c_str()) + 1) * sizeof(wchar_t));
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

CLogger* CApp::GetLogger()
{
	return m_pLogger;
}