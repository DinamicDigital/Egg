#include "Window.h"
#include "../Util/Debug.h"
#include <GLFW/glfw3.h>

typedef struct egg_window {
	
	WindowSettings* window_settings;


	// Internal Stuff
	GLFWwindow* window;

} Window;

static Window window;

void init_window()
{
	if (!glfwInit())
	{
		debug_popup("GLFW could not init.");
	}
		
	
	window.window = glfwCreateWindow(window.window_settings->width, window.window_settings->height, window.window_settings->caption, 0, 0);
	if (!window.window)
	{
		glfwTerminate();
		debug_popup("Window not working!");
		return;
	}
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window.window);

	while (!glfwWindowShouldClose(window.window))
	{
		/* Render here */

		/* Swap front and back buffers */
		glfwSwapBuffers(window.window);

		/* Poll for and process events */
		glfwPollEvents();
	}


	
}

void API setWindowCaption(const char* caption)
{
	glfwSetWindowTitle(window.window, caption);
}

void API setWindowSettings(WindowSettings* window_settings)
{
	window.window_settings = window_settings;
}
