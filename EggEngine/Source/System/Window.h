#pragma once
#include "../Util/API.h"
#include <Windows.h>

typedef struct egg_window {
	char* caption;

	// Internal Stuff
	HWND hWindow;
	LPCSTR* windowClassName;
	WNDCLASS windowClass;

} Window;

LRESULT CALLBACK WindowProc(
	HWND   hwnd,
	UINT   uMsg,
	WPARAM wParam,
	LPARAM lParam
);

void InitWindow();

void API setWindowCaption();