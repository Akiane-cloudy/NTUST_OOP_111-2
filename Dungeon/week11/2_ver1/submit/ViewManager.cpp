#include "ViewManager.h"
shared_ptr<GLFWwindow> ViewManager::window;

void ViewManager::show()
{
	ViewManager::init();
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window.get()))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Poll for and process events */
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
		{
			ImGui::Begin("Hello test windows");
			ImGui::End();
		}
		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window.get(), &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window.get());
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window.get());
	glfwTerminate();
}

void ViewManager::init()
{
	/* Initialize the library */
	if (!glfwInit()) return;

	/* Create a windowed mode window and its OpenGL context */
	window = (shared_ptr<GLFWwindow>)glfwCreateWindow(640, 480, "Dungeon", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window.get());

	if (gladLoadGL() == 0)
	{
		return;
	}

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	//ImGui::StyleColorsDark();
	ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window.get(), true);
	ImGui_ImplOpenGL3_Init("#version 130");
}
