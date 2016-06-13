#pragma once
#include <SFML\Graphics.hpp>
class ResourceManager
{
public:
	sf::Texture FloorTexture;
	sf::Texture PlayerTexture;
	sf::Texture TracerTexture;
	sf::Texture TracerTerminationTexture;
	ResourceManager();
	~ResourceManager();
	void InitTextures();
};

