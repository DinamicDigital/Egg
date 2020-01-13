#include "Window.h"
#include "../Util/Debug.h"

static Window window;

void API init_window()
{
	window = {};
	window.caption = (char*) "Egg Engine - Use set_window_caption() to change window title.";
	window.windowClassName = (char*) "EGG_WINDOW";
	window.windowClass = { };
	window.windowClass.lpfnWndProc = WindowProc;
	window.windowClass.lpszClassName = window.windowClassName;
	
	RegisterClass(&(window.windowClass));

	window.hWindow = CreateWindowExA(0, window.windowClassName, window.caption, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0, GetModuleHandle(0), 0);

	if (window.hWindow == 0)
	{
		debug_message("Window failed to init.");
		return;
	}

	ShowWindow(window.hWindow, SW_SHOW);

	
}

void API setWindowCaption(const char* caption)
{
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

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}