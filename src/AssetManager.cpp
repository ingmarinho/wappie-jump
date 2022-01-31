#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

namespace WappieJump
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			_textures[name] = tex;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name)
	{
		return _textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			_fonts[name] = font;
		}
	}

	void AssetManager::LoadSound(std::string name, std::string fileName)
	{
		sf::SoundBuffer soundBuffer;
		sf::Sound sound; 

		if (soundBuffer.loadFromFile(fileName))
		{
			sound.setBuffer(soundBuffer);
			_sounds[name] = sound;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return _fonts.at(name);
	}

	sf::Sound &AssetManager::GetSound(std::string name)
	{
		// sf::Sound sound;
		// sound.setBuffer(_soundBuffers.at(name));
	
		return _sounds.at(name);
	}
}