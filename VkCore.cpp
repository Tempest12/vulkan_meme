#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>

#include "Config.hpp"
#include "Log.hpp"
#include "Main.hpp"
#include "VkCore.hpp"
#include "VkWindow.hpp"

VkCore::VkCore(void)
{
    memset(&this->vkLogicalDevice , 0, sizeof(VkDevice));
    memset(&this->vkPhysicalDevice, 0, sizeof(VkPhysicalDevice));
    memset(&this->vkInstance      , 0, sizeof(VkInstance));
}

VkCore::~VkCore(void)
{
    vkDestroyInstance(this->vkInstance, NULL);

    delete this->window;
}

void VkCore::checkAndDie(char* suicideNote)
{
    if(this->vkLastResult != VK_SUCCESS)
    {
        Main::die(suicideNote);
    }
}

void VkCore::findDeviceQueueFamily(void)
{
    unsigned int commandQueueCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(this->vkPhysicalDevice, &commandQueueCount, NULL);

    if(commandQueueCount == 0)
    {
        Main::die("Physical GPU says it doesn't have any queue families.");
    }
}

void VkCore::init(void)
{
    //VK_DEFINE_HANDLE(VkInstance);
    VkInstance hate;
    memset(&hate, 0, sizeof(VkInstance));

    this->window = new VkWindow();

    VkApplicationInfo    vkAppInfo;
    VkInstanceCreateInfo vkCreateInfo;
    memset(&vkAppInfo   , 0, sizeof(VkApplicationInfo));
    memset(&vkCreateInfo, 0, sizeof(VkInstanceCreateInfo));

    vkAppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vkAppInfo.pApplicationName   = "Vulkan_Demo";
    vkAppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    vkAppInfo.pEngineName        = "No Engine";
    vkAppInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    vkAppInfo.apiVersion         = VK_API_VERSION_1_0;

    vkCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    vkCreateInfo.pApplicationInfo        = &vkAppInfo;
    vkCreateInfo.enabledExtensionCount   = this->window->extensionCount;
    vkCreateInfo.ppEnabledExtensionNames = this->window->extensionNames;
    vkCreateInfo.enabledLayerCount       = 0;

    this->vkLastResult = vkCreateInstance(&vkCreateInfo, NULL, &this->vkInstance);
    this->checkAndDie((char*)"Couldn't create VkInstance!");

    this->pickDevice();
    this->findDeviceQueueFamily();
}

void VkCore::pickDevice(void)
{
    unsigned int deviceCount = 0;
    vkEnumeratePhysicalDevices(this->vkInstance, &deviceCount, NULL);

    if(deviceCount == 0)
    {
        Main::die("No GPU's with Vulkan support found");
    }

    std::vector<VkPhysicalDevice> devices = std::vector<VkPhysicalDevice>(deviceCount);
    vkEnumeratePhysicalDevices(this->vkInstance, &deviceCount, devices.data());

    // Just take the first device for now:
    this->vkPhysicalDevice = devices[0];
}

void VkCore::uninit(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Static Functions:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags,
                                                    VkDebugReportObjectTypeEXT objType,
                                                    uint64_t obj,
                                                    size_t location,
                                                    int32_t code,
                                                    const char* layerPrefix,
                                                    const char* msg,
                                                    void* userData)
{
    
}
