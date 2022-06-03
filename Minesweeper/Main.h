#pragma once
#include "wx/wx.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
public:
	int WIDTH = 10;
	int HEIGHT = 10;
	wxButton **Button;
	int *Field = nullptr;
	bool FirstClick = true;
	void ButtonClicked(wxCommandEvent &Button);

	wxDECLARE_EVENT_TABLE();

};

