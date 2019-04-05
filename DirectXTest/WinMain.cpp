//#include <Windows.h>
//#include "WindowsMessageMap.h"
//#include <sstream>
#include "Windows.h"

///LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
///{
///	static WindowsMessageMap mm;
///	OutputDebugString(mm(msg, lParam, wParam).c_str());
///
///	switch( msg )
///	{
///	case WM_CLOSE:
///		PostQuitMessage(69);
///		break;
///	case WM_KEYDOWN:
///		if (wParam == 'F')
///		{
///			SetWindowText(hWnd, "Respects");
///		}
///		break;
///	case WM_KEYUP:
///		if (wParam == 'F')
///		{
///			SetWindowText(hWnd, "Dangerfield");
///		}
///		break;
///	case WM_CHAR:
///		{
///			static std::string title;
///			title.push_back((char)wParam);
///			SetWindowText(hWnd, title.c_str());
///		}
///		break;
///	case WM_LBUTTONDOWN:
///		{
///			POINTS pt = MAKEPOINTS(lParam);
///			std::ostringstream oss;
///			oss << "(" << pt.x << "," << pt.y << ")";
///			SetWindowText(hWnd, oss.str().c_str());
///		}
///	}
///	return DefWindowProc(hWnd, msg, wParam, lParam);
///}


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