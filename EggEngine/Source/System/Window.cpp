#include "Window.h"
#include "../Util/Debug.h"

typedef struct egg_window {
	
	WindowSettings* window_settings;


	// Internal Stuff
	HWND hWindow;
	char* windowClassName;
	WNDCLASS windowClass;

} Window;

static Window window;

void init_window()
{
	
	window.windowClassName = (char*) "EGG_WINDOW";
	window.windowClass = { };
	window.windowClass.lpfnWndProc = WindowProc;
	window.windowClass.lpszClassName = window.windowClassName;
	
	RegisterClass(&(window.windowClass));
	
	printf("%s\n%d\n%d\n%d\n", window.window_settings->caption, window.window_settings->width, window.window_settings->height, window.window_settings->resizable);
	
	window.hWindow = CreateWindowExA(0, window.windowClassName, window.window_settings->caption, 
		(window.window_settings->resizable == true) ? WS_OVERLAPPEDWINDOW : WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,
		CW_USEDEFAULT, CW_USEDEFAULT, window.window_settings->width, window.window_settings->height,
		0, 0, GetModuleHandle(0), 0);

	if (window.hWindow == 0)
	{
		debug_popup("Window failed to init.");
		return;
	}

	ShowWindow(window.hWindow, SW_SHOW);

	
}

void API setWindowCaption(const char* caption)
{
	window.window_settings->caption = (char*) caption;
	SetWindowTextA(window.hWindow, caption);
}

LRESULT CALLBACK WindowProc(
	HWND   hwnd,
	UINT   uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_SIZE:
	{
		
	} break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// All painting occurs here, between BeginPaint and EndPaint.

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	} break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
	break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void API setWindowSettings(WindowSettings* window_settings)
{
	window.window_settings = window_settings;
}
