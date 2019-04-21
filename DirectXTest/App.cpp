#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	: wnd(800, 600, "Donkey box")
{}

int App::Go()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxilliray WM_CHAR message from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	// chake if GetMessage call itself borked
	if (gResult == -1)
	{
		throw CHWND_LAST_EXCEPT();
	}

	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}