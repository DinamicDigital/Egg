#include "Window.h"
#include "../Util/Debug.h"
#include <gl/GL.h>
#include <GLFW/glfw3.h>

typedef struct egg_window {
	
	WindowSettings* window_settings;


	// Internal Stuff
	GLFWwindow* window;

} Window;

static Window window;

void init_window()
{
	
	

	if (window.hWindow == 0)
	{
		debug_popup("Window failed to init.");
		return;
	}


	
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
		static PAINTSTRUCT ps;
	case WM_CREATE:
	{
		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		HDC deviceContext = GetDC(hwnd);
		// Windows chooses this for us.
		int pixelFormat = ChoosePixelFormat(deviceContext, &pfd);
		SetPixelFormat(deviceContext, pixelFormat, &pfd);

		window.glContext = wglCreateContext(deviceContext);
		wglMakeCurrent(deviceContext, window.glContext);

		printf("GL Version %s", glGetString(GL_VERSION));

		glViewport(0, 0, window.window_settings->width, window.window_settings->height);


		glClearColor(0.3f, 0.5f, 0.1f, 1.0f);
		
		
	} break;
	case WM_SIZE:
	{
		
	} break;
	case WM_PAINT:
	{
		
		BeginPaint(hwnd, &ps);
		
		EndPaint(hwnd, &ps);
	} break;
	case WM_DESTROY:
		wglDeleteContext(window.glContext);
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
