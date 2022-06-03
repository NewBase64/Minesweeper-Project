#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(10000, ButtonClicked)
END_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(600, 600))
{
	Button = new wxButton * [WIDTH * HEIGHT];
	wxGridSizer* Grid = new wxGridSizer(WIDTH, HEIGHT, 0, 0);
	Field = new int[WIDTH * HEIGHT];


	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			Button[j * WIDTH + i] = new wxButton(this, 10000 + (j * WIDTH + i));
			Button[j * WIDTH + i]->SetFont(font);
			Grid->Add(Button[j * WIDTH + i], 1, wxEXPAND | wxALL);
			Button[j * WIDTH + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::ButtonClicked, this);
			Field[j * WIDTH + i] = 0;


		}
	}
	this->SetSizer(Grid);
	Grid->Layout();


}

Main::~Main()
{

	delete[] Button;
	delete Field;
}


void Main::ButtonClicked(wxCommandEvent& Buttn)
{
	int x = (Buttn.GetId() - 10000) % WIDTH;
	int y = (Buttn.GetId() - 10000) / WIDTH;

	if (FirstClick)
	{
		int mines = 30;

		while (mines)
		{

			int Randx = rand() % WIDTH;
			int Randy = rand() % HEIGHT;

			if (Field[Randy * WIDTH + Randx] == 0 && Randx != x && Randy != y)
			{
				Field[Randy * WIDTH + Randx] = -1;
				mines--;

			}
		}
		FirstClick = false;
	}
	Button[y * WIDTH + x]->Enable(false);

	if (Field[y * WIDTH + x] == -1)
	{
		wxMessageBox("BOOOOOOM!! -YOU LOSE :[");

		FirstClick = true;
		for (int x = 0; x < WIDTH; x++)
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				Field[y * WIDTH + x] = 0;
				Button[y * WIDTH + x]->SetLabel("");
				Button[y * WIDTH + x]->Enable(true);
			}
		}
	}
	else
	{
		int mine_counter = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < WIDTH && y + j >= 0 && y + j < HEIGHT)
				{
					if (Field[(y + j)*WIDTH + (x + i)] == -1)
						mine_counter++;

				}
			}

			if (mine_counter > 0)
			{
				Button[y * WIDTH + x]->SetLabel(std::to_string(mine_counter));
			}


		

	}
	Buttn.Skip();
}