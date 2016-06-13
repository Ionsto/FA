#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	InitTextures();
}


ResourceManager::~ResourceManager()
{
}
void ResourceManager::InitTextures()
{
	FloorTexture = sf::Texture();
	FloorTexture.loadFromFile("./Textures/Floor.png");
	TracerTexture = sf::Texture();
	TracerTexture.loadFromFile("./Textures/Ray.png");
}