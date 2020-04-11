#pragma once
#include <SFML/Audio.hpp>

class Audio
{
public:
   Audio();

   void playMusic();
   void stopMusic();
   void fadeOutMusic();
private:
   sf::Music music;
   const std::string musicFileName;
};