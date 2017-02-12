#include <iostream>
//#include <GLFW/glfw3.h>

#include "src/graphics/window.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	Window window("Sparky!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;
		if (window.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "Key Pressed!" << std::endl;
		}
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
			std::cout << "Mouse Pressed!" << std::endl;
		}
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
	//system("PAUSE");
	return 0;
}