#pragma once
#include "../Util/API.h"
#include <Windows.h>

typedef struct egg_window {
	// My stuff
	char* caption;
	int width; int height;

	

	// Internal Stuff
	HWND hWindow;
	char* windowClassName;
	WNDCLASS windowClass;

} Window;

LRESULT CALLBACK WindowProc(
	HWND   hwnd,
	UINT   uMsg,
	WPARAM wParam,
	LPARAM lParam
);

void init_window();

void API setWindowCaption(const char* caption);