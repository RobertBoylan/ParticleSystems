#include "Demo.h"

Demo::Demo() {

	gravity = -9.81f;
	particlesPerSecond = 1000.0f;
	cameraPosition = fountainDirection = vec3(0.0f, 0.0f, 0.0f);
	pause = whiteBackground = false;
}

int Demo::CreateDemoWindow(int _mode) {

	mode = _mode;

	/* Open a window and create its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "ParticleSystem", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	/* Ensure we can capture the escape key being pressed below */
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	/* Hide the mouse and enable unlimited movement */
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	/* Set the mouse at the center of the screen */
	glfwPollEvents();
	glfwSetCursorPos(window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void Demo::DemoInitialize() {

	particle.LoadParticles(mode);
}

void Demo::DemoDisplay() {

	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)) {
		
		particle.DrawParticles(window, mode, gravity, particlesPerSecond, fountainDirection, pause, whiteBackground);
		KeyboardOperations();
		
		/* Swap buffers */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Demo::CleanUp() {

	particle.CleanUp(window);
}

void Demo::KeyboardOperations() {

	if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) {

		if (gravity <= 15.0f) {

			gravity += 0.02f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS) {

		if (gravity >= -100.0f) {

			gravity -= 0.02f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {

		if (fountainDirection.z <= 4.0f) {

			fountainDirection.z += 0.01f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

		if (fountainDirection.z >= -4.0f) {

			fountainDirection.z -= 0.01f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

		if (fountainDirection.x <= 4.0f) {

			fountainDirection.x += 0.01f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {

		if (fountainDirection.x >= -4.0f) {

			fountainDirection.x -= 0.01f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {

		if (particlesPerSecond > 0.0f) {
			
			particlesPerSecond -= 10.0f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {

		if (particlesPerSecond < 15000.0f) {

			particlesPerSecond += 10.0f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {

		pause = false;
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {

		pause = true;
	}

	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {

		whiteBackground = !whiteBackground;
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {

		particlesPerSecond = 1000.0f;
		gravity = -9.81f;
		fountainDirection = vec3(0.0f, 0.0f, 0.0f);
		whiteBackground = false;
	}

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {

		mode = SNOW_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {

		mode = RAIN_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {

		mode = STARS_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {

		mode = CLOUD_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {

		mode = FOUNTAIN_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {

		mode = SMOKE_DEMO;
	}

	else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {

		mode = FIRE_DEMO;
	}
}
