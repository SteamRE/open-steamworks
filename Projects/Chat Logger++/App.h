/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>

class CConfigurationDialog;
class CTaskBarIcon;
class CLogger;

class CApp : public wxApp
{
public:
	CApp();
    virtual bool OnInit();
	virtual void CleanUp();

	void Message(const wxString& message);
	void Warning(const wxString& message);

	enum EIcon
	{
		k_EIconNormal = 0,
		k_EIconWarning,
		k_EIconDisconnected,
	};
	void SetTrayIcon(EIcon eIcon, const wxString& text = _T(""));

	CLogger* GetLogger();

private:
	static void InvalidParameterHandler(const wchar_t * expression, const wchar_t * function, const wchar_t * file, unsigned int line, uintptr_t pReserved);

	void OnTaskBarIconClick(wxTaskBarIconEvent& event);
	void OnAutoStartButtonClick(wxCommandEvent& event);
	void OnConfigurationButtonClick(wxCommandEvent& event);
	void OnExitButtonClick(wxCommandEvent& event);
	void OnConfigurationWindowClosed(wxCloseEvent& event);

	CConfigurationDialog* m_pConfigurationDialog;
	CTaskBarIcon* m_pTaskBarIcon;

	CLogger* m_pLogger;

	DECLARE_EVENT_TABLE()
};
DECLARE_APP(CApp)