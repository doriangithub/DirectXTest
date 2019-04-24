#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	: wnd(800, 600, "Donkey box")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block...
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're ...
			return *ecode;
		}
		DoFrame();
	}
	
}

void App::DoFrame()
{
	//const float t = timer.Peek();
	//std::ostringstream oss;
	//oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	//wnd.SetTitle(oss.str());
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}