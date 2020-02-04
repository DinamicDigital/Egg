#include "Engine.h"
#include "../System/Window.h"
#include <GLFW/glfw3.h>

void API StartEngine()
{
	init_window();

	glfwTerminate();
}
