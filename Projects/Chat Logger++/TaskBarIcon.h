/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#pragma once

#include <wx/taskbar.h>


class CTaskBarIcon : public wxTaskBarIcon
{
public:

	enum EIcon
	{
		k_EIconNone = 0,
		k_EIconInfo,
		k_EIconWarning,
		k_EIconError,
	};
	void ShowMessage(const wxString& title, const wxString& message, EIcon eIcon = k_EIconInfo);
};
