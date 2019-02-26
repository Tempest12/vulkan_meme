#ifndef _VK_FUNCTION_TABLE_HPP
#define _VK_FUNCTION_TABLE_HPP

void  initVulkanProcTable(VkInstance* vkInstance);
GLFWvkproc getProcAddressHelper(const char* procName);

//Vulkan function table:
//extern VkResult (*vkCreateInstance) (const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
//extern void     (*vkDestroyInstance)(VkInstance instance, const VkAllocationCallbacks* pAllocator);

#endif