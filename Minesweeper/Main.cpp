#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
		EVT_BUTTON(10000,ButtonClicked)
END_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(600, 600))
{
	Button = new wxButton * [WIDTH * HEIGHT];
	wxGridSizer* Grid = new wxGridSizer(WIDTH, HEIGHT, 0, 0);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			Button[j * WIDTH + i] = new wxButton(this, 10000 + (j * WIDTH + i));
			Grid->Add(Button[j * WIDTH + i], 1, wxEXPAND | wxALL);
			Button[j * WIDTH + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::ButtonClicked, this);


		}
	}
	this->SetSizer(Grid);
	Grid->Layout();


}

Main::~Main()
{

	delete[] Button;
}


void Main::ButtonClicked(wxCommandEvent &Button)
{

	
	Button.Skip();
}