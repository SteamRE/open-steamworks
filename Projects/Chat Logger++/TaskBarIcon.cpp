/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#include "TaskBarIcon.h"
#include <wx/wx.h>
#include <Windows.h>

void CTaskBarIcon::ShowMessage(const wxString& title, const wxString& message, EIcon eIcon)
{
	NOTIFYICONDATA nid;
	memset(&nid, 0, sizeof(nid));

	nid.cbSize              = sizeof(nid);

	nid.hWnd                = (HWND) ((wxFrame*)this->m_win)->GetHWND();
	nid.uID                 = 99;
	nid.uFlags              = NIF_INFO;
	nid.dwInfoFlags         = eIcon;
	wcscpy(nid.szInfoTitle, title.Mid(0, (sizeof(nid.szInfoTitle) / sizeof(*nid.szInfoTitle)) - 1).wc_str());
	wcscpy(nid.szInfo, message.Mid(0, (sizeof(nid.szInfo) / sizeof(*nid.szInfo)) - 1).wc_str());

	Shell_NotifyIcon(NIM_MODIFY, &nid);
}