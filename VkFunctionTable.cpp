#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include "Main.hpp"
#include "VkFunctionTable.hpp"

void initVulkanProcTable(VkInstance* vkInstance)
{

}

void* getProcAddressHelper(VkInstance* vkInstance, const char* procName)
{
    GLFWvkproc temp = glfwGetInstanceProcAddress(*vkInstance, procName);

    if(temp == NULL)
    {
        Main::die("Failed to load proc address for function: %s", procName);
    }

    return reinterpret_cast<void*>(temp);
}

//Function List:
//VkResult (*vkCreateInstance) (const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
//void     (*vkDestroyInstance)(VkInstance instance, const VkAllocationCallbacks* pAllocator);