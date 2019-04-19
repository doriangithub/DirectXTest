#include <sstream>
#include "Windows.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int       nCmdShow)
{
	try
	{
		Window wnd(800, 300, "Window - 1 ");
		//Window wnd2(600, 400, "Window - 2 ");

		// message pump
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// test code
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("Gone");
					break;
				case Mouse::Event::Type::Move:
				{
					std::ostringstream oss;
					oss << "Mouse move to (" << std::to_string(wnd.mouse.GetPosX()) << ":"
						<< std::to_string(wnd.mouse.GetPosY()) << ")";
					wnd.SetTitle(oss.str());
				}
				break;
				}
			}

			if (wnd.kbd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "Samethng happaned!", "Space key was pressed!", 0);
			}
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
	catch(const ChiliException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch(const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception" , MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}