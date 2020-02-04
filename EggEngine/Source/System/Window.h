#pragma once
#include "../Util/API.h"
#include <Windows.h>

typedef struct egg_win_settings {
	// My stuff
	char* caption;
	int width; int height;
	bool resizable;
	

} WindowSettings;

void init_window();

void API setWindowSettings(WindowSettings* window_settings);

void API setWindowCaption(const char* caption);