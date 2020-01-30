#include "Engine.h"
#include "../System/Window.h"
#include <Windows.h>
#include <gl/GL.h>
void API StartEngine()
{
	init_window();
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
