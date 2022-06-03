#pragma once
#include "wx/wx.h"
#include "Main.h"
class Application : public wxApp
{
public:
	Application();
	~Application();

private:
	Main* m_frame1 = nullptr;
public:
	virtual bool OnInit();

};

