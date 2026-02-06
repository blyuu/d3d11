#include <Windows.h>

//DirectX3D Header Files
#include <d3d11.h>
#include <d3dcompiler.h>


LRESULT CALLBACK wndproc(HWND handle, UINT message, WPARAM w_param, LPARAM l_param)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(handle, message, w_param, l_param);
	}

	return 0;
}


int WINAPI WinMain(HINSTANCE cinstance, HINSTANCE pinstance, LPSTR lpstr, int cmd)
{
	// Create Window Class and Handler
	WCHAR WindowClass[] = L"breakoutclass";
	WCHAR Title[] = L"Break Out";

	WNDCLASSW windowclassw = { 0, wndproc, 0, 0, 0, 0 ,0 ,0, 0, WindowClass };

	RegisterClassW(&windowclassw);

	HWND handle = CreateWindowExW(0, WindowClass, Title, WS_VISIBLE | WS_POPUP | WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, CW_USEDEFAULT, 1600, 900, NULL, NULL, cinstance, NULL);


	bool exit = false;

	while (exit == false)
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				exit = true;
				break;
			}
		}
	}

	return 0;
}