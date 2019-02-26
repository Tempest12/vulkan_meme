#include <iostream>
#include <GLFW/glfw3.h>

#include "Config.hpp"
#include "Log.hpp"
#include "Main.hpp"
#include "VkWindow.hpp"

VkWindow::VkWindow(void)
{
    // Get Window Config:
    this->windowHeight = Util::Config::convertSettingToInt("Window", "window_height");
    this->windowWidth  = Util::Config::convertSettingToInt("Window", "window_width");

    // Init GLFW stuff:
    if(glfwInit() == false)
    {
        Main::die("Failed to initialize glfw.");
    }

    // Set GLFW to use Vulkan instead of GL:
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    this->window = glfwCreateWindow(this->windowWidth, this->windowHeight, "Vulkan_Demo", NULL, NULL);

    // Get the vulkan extension information from GLFW:
    this->extensionNames = glfwGetRequiredInstanceExtensions(&this->extensionCount);

    // Set our error call back:
    glfwSetErrorCallback(VkWindow::handleGLFWErrors);
    glfwSetKeyCallback(this->window, VkWindow::handleKeyboardEvents);
}


VkWindow::~VkWindow(void)
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}


void VkWindow::handleKeyboardEvents(GLFWwindow* window, int key, int scanCode, int action, int mods)
{
    std::cout << "Key pressed, key: " << key << std::endl;

    if(key == GLFW_KEY_ESCAPE)
    {
        Main::breakRunLoop();
    }
}

void VkWindow::handleGLFWErrors(int errorCode, const char* errorMessage)
{
    Util::Log::writeError("Got an error from GLFW. Here's the message we got:");
}