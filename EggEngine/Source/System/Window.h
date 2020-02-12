#pragma once
#include "../Util/API.h"
#include "../Vendor/glad/glad.h"
#include "GLFW/glfw3.h"

typedef struct egg_win_settings {
	// My stuff
	char* caption;
	int width; int height;
	bool resizable;
	

} WindowSettings;

typedef struct egg_window {

	WindowSettings* window_settings;


	// Internal Stuff
	GLFWwindow* window;

} Window;

Window window;

void init_window();

void API setWindowSettings(WindowSettings* window_settings);

void API setWindowCaption(const char* caption);