#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace WappieJump
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

		void LoadSound(std::string name, std::string fileName);
		sf::Sound &GetSound(std::string name);

		void addBuffer(sf::SoundBuffer soundBuffer);

		std::map<std::string, sf::Sound> &GetSoundMap();

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Sound> _sounds;
		std::map<std::string, sf::SoundBuffer> _soundBuffers;
		std::map<std::string, sf::Font> _fonts;
	};
}
