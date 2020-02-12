#include "Engine.h"
#include "../System/Window.h"

#include <GLFW/glfw3.h>

void API StartEngine()
{
	init_window();

	while (!glfwWindowShouldClose(window.window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		/* Swap front and back buffers */
		glfwSwapBuffers(window.window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	
	glfwTerminate();
}
