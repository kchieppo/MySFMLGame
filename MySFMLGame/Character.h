#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.h"

/*
Abstract class for the play controlled character and NPCs.
*/
class Character
{
public:
	Character();

   // pos is the coordinate of the top-left corner of the sprite.
	Character(const sf::Vector2f& pos);

   // Draws the character to the screen. Called every frame.
	virtual void draw(sf::RenderTarget& rt) const;

   // Sets a variable that indicates which animation to use. E.g., if dir is set
   // to {-1, 0}, the character's "walking left" animation will be used.
	virtual void setAnimationIndex(const sf::Vector2f& dir) = 0;

   // Update's the character, given the time passed each frame. Called every
   // frame.
	virtual void update(const float& dt) = 0;
protected:
	sf::Sprite sprite;

   // The velocity of the character.
	sf::Vector2f vel;
};