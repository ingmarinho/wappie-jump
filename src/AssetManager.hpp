#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/// @file

namespace WappieJump
{
	/// Assetmanager
	///
	/// This class handles the loading of the textures, font and sounds/soundbuffers.
	/// 

	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		/// Loads a texture from a file and saves it in the textures map
		void LoadTexture(std::string name, std::string fileName);
		/// Returns a texture from the textures map
		sf::Texture &GetTexture(std::string name); 

		/// Loads a font from a file and saves it in the fonts map
		void LoadFont(std::string name, std::string fileName); 
		/// Returns a font from the fonts map
		sf::Font &GetFont(std::string name);					

		/// Loads an audio file into a soundbuffer / sound object, these are stored in two different maps
		void LoadSound(std::string name, std::string fileName); 
		/// Returns a sound object 
		sf::Sound &GetSound(std::string name); 
		/// Returns a sound from the sound map
		std::map<std::string, sf::Sound> &GetSoundMap(); 

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Sound> _sounds;
		std::map<std::string, sf::SoundBuffer> _soundBuffers;
		std::map<std::string, sf::Font> _fonts;
	};
}
