#include "Audio.h"
#include <iostream>
#include <chrono>

Audio::Audio()
   :
   musicFileName{ "Audio\\Music\\604-Orange-St-69.wav" }
{
}

void Audio::playMusic()
{
   if (!music.openFromFile(musicFileName))
      std::cout << "Error opening " << musicFileName << std::endl;
   music.play();
}

void Audio::stopMusic()
{
   music.stop();
}

void Audio::fadeOutMusic()
{

}