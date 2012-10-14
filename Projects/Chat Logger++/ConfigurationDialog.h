/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#pragma once

#include <wx/wx.h>
#include <wx/config.h>
#include <wx/notebook.h>
#include <wx/filepicker.h>

class CConfigurationDialog : public wxDialog
{
public:
	CConfigurationDialog();

private:
	void UpdatePreviews();

	void OnInputChange(wxCommandEvent& event);
	void OnTextURLEvent(wxTextUrlEvent& event);
	void OnButton(wxCommandEvent& event);

	bool m_bEnablePreviews;

	wxConfig m_config;

	wxNotebook* m_pNotebook;
	wxPanel* m_pLoggingPanel;
	wxPanel* m_pHelpPanel;

	wxDirPickerCtrl *m_pLogDirPicker;

	wxTextCtrl *m_pFilenameInput;
	wxTextCtrl *m_pReplacementInput;
	wxTextCtrl *m_pMessageInput;
	wxTextCtrl *m_pEmoteInput;
	wxTextCtrl *m_pSeparationInput;
	wxTextCtrl *m_pDateInput;
	wxTextCtrl *m_pTimeInput;

	wxCheckBox* pUnstableCheckBox;

	wxStaticText *m_pFilenamePreviewLabel;
	wxStaticText *m_pMessagePreviewLabel;
	wxStaticText *m_pEmotePreviewLabel;
	wxStaticText *m_pDatePreviewLabel;
	wxStaticText *m_pTimePreviewLabel;

	DECLARE_EVENT_TABLE()
};