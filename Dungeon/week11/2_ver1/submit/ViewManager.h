#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <iostream>
using namespace std;

class ViewManager
{
public:
	static shared_ptr<GLFWwindow> window;
	static void show();
	static void init();
};

