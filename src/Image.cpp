/**
 * Project: EDEF
 * @file Image.cpp
 * @date 11. 4. 2018
 * @author xdocek09
 * @brief 
 */

/*** End of file: Image.cpp ***/
#include "Image.h"
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_GIF
#include "stb_image.h"

Image::Image(const std::string& path) {
	load(path);
}

void Image::load(const std::string& path){
	free();
	pixels=stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 0);

	std::string msg("Invalid image: ");
	msg+=path;
	if(pixels == NULL) throw std::runtime_error(msg);
}

Image::~Image(){
	free();
}

void Image::free(){
	if(pixels!=nullptr){
		stbi_image_free(pixels);
	}
}