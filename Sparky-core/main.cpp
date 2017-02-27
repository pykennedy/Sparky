#include <iostream>
#include "src/maths/maths.h"
#include "src/graphics/window.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Window window("Sparky!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.2f, 0.3f, 0.8f, 1.0f);

	vec4 c = a + b;

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();

	position.elements[12] = 2.0f;

	vec4 c0 = position.columns[3];
	vec4 c1 = position.getColumn(3);
	std::cout << c0 << std::endl;
	std::cout << c1 << std::endl;

	while (!window.closed()) {
		window.clear();
		//std::cout << a << std::endl;
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