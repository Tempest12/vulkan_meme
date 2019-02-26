#ifndef _VK_WINDOW_HPP
#define _VK_WINDOW_HPP

#include <queue>

// Forward declarations:
class GLFWwindow;

class VkWindow
{
// Variabes:
public:

    const char** extensionNames;

    int windowWidth;
    int windowHeight;

    unsigned int extensionCount;

    GLFWwindow* window;

protected:
private:

// Functions:
public:

    VkWindow(void);
    ~VkWindow(void);

protected:
private:


// Static Variables:
public:

    static std::queue<int>* keysDown;

protected:
private:

// Static Functions:
public:

    static void handleKeyboardEvents(GLFWwindow* window, int key, int scanCode, int action, int mods);
    static void handleGLFWErrors(int errorCode, const char* errorMessage);

protected:
private:
};

#endif