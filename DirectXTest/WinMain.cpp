//#include <Windows.h>
//#include "WindowsMessageMap.h"
//#include <sstream>
#include "Windows.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int       nCmdShow)
{
	Window wnd(800, 300, "Window - 1 ");
	Window wnd2(600, 400, "Window - 2 ");

	// message pump
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}