#ifndef _VK_CORE_HPP
#define _VK_CORE_HPP

#include <vulkan/vulkan.h>

// Foward declarations:
class VkWindow;

class VkCore
{
// Vairables:
public:

    VkWindow*        window;

    VkDevice         vkLogicalDevice;
    VkInstance       vkInstance;
    VkPhysicalDevice vkPhysicalDevice;
    VkResult         vkLastResult;

protected:
private:

// Functions:
public:

    VkCore(void);
    ~VkCore(void);

    void checkAndDie(char* suicideNote);
    void draw(void);
    void findDeviceQueueFamily(void);
    void init(void);
    void pickDevice(void);
    void update(float time);
    void uninit(void);

protected:
private:

//Static Functions:
public:

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags,
                                                    VkDebugReportObjectTypeEXT objType,
                                                    uint64_t obj,
                                                    size_t location,
                                                    int32_t code,
                                                    const char* layerPrefix,
                                                    const char* msg,
                                                    void* userData);

protected:
private:
};



#endif