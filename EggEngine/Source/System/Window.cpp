#include "Window.h"

static Window window;

void InitWindow()
{
	window.windowClassName = L"Egg Engine - Set game title with setWindowCaption() function!";
	window.windowClass = { };
	window.windowClass.lpfnWndProc = WindowProc;
	window.windowClass.lpszClassName = window.windowClassName;
}

void API setWindowCaption()
{

}
