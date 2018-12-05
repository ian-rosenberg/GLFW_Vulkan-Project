#pragma once

#include <string.h>
#include <stdio.h>
#include <vector>

#include "Queue_Wrapper.h"
#include "Pipeline_Wrapper.h"


class Swapchain_Wrapper
{
private:
	VkSurfaceCapabilitiesKHR			capabilities;
	std::vector<VkSurfaceFormatKHR>		formats;

	VkFormat							swapImageFormat;

	std::vector<VkPresentModeKHR>		presentModes;

	VkExtent2D							extent;

	int									chosenFormat;
	int									chosenPresentMode;

	VkDevice							logDevice;

	uint32_t							swapchainCount;
	VkSwapchainKHR						swapchain;
	uint32_t							swapchainImageCount;

	std::vector<VkImage>				swapImages;
	std::vector<VkImageView>			imageViews;

	std::vector<VkFramebuffer>			frameBuffers;

public:
	Swapchain_Wrapper();
	~Swapchain_Wrapper();

	void SwapchainInit(VkPhysicalDevice device, VkDevice logicalDevice, VkSurfaceKHR surface, uint32_t width, uint32_t height, Queue_Wrapper *qWrapper);

	int ChooseFormat();

	VkFormat GetFormat(){ return swapImageFormat; }

	int GetPresentationMode();
	VkSwapchainKHR GetSwapchain(){ return swapchain; }

	VkExtent2D ConfigureExtent(int width, int height);
	VkExtent2D GetExtent(){return extent;}

	std::vector<VkImageView> GetImageViews(){return imageViews;}

	void CreateSwapchain(VkDevice lDevice, VkSurfaceKHR surface, Queue_Wrapper *qWrapper);

	VkImageView CreateImageView(VkImage image, VkFormat format, VkDevice lDevice);

	void CreateFrameBuffers(Pipeline* pipe);

	std::vector<VkFramebuffer> GetFrameBuffers(){ return frameBuffers; }
};