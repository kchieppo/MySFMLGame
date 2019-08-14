#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

/*
Displays text to the screen.
*/
class DialogueBox
{
public:
	DialogueBox(std::string& message);
   // Draws the dialogue box to the screen. Called every frame.
	void draw(sf::RenderTarget& rt) const;
   // Draws more text to the render texture containing the dialogue box that's
   // drawn to the screen. This makes it so the text comes in a little at a
   // time. More text is added after incurring enough delta time, stored in the
   // time variable. Called every frame.
	void update(float dt);
   // Resets the dialogue box. Specifically, variables are reset, and an empty
   // dialogue box is drawn to the render texture to prepare it for future text.
	void reset();
	const sf::RenderTexture& getRenderTexture();
private:
   // Draws more text to the dialogue box. Called by update once enough time
   // incurred.
	void drawToRenderTexture();
   // Breaks up dialogue string into words.
	void tokenize(std::string& message);
   // Returns true if there are more words to be drawn to the dialogue box.
	bool hasMoreWords();
private:
	static constexpr float diagBoxXLoc = 200.0f;
	static constexpr float diagBoxYLoc = 450.0f;
	static constexpr float diagBoxWidth = 400.0f;
	static constexpr float diagBoxHeight = 100.0f;
   // Padding between left and right edges of dialogue box and words.
	static constexpr float lineWidthPadding = 5.0f;
   // Padding between rows of words.
	static constexpr float lineHeightPadding = 2.0f;
   // Amount of time that must pass before next words are drawn to the dialogue
   // box.
	static constexpr float holdTime = 0.2f;
   // Thickness of the dialogue box outline.
	static constexpr float outlineThickness = 5.0f;
   // Stores total accrued time. If greater than holdTime, more text is drawn to
   // the dialogue box.
	float time = 0.0f;
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;
	sf::RectangleShape rectangleShape;
	sf::Font font;
	sf::Text text;
	std::vector<std::string> tokenizedMessage;
	std::vector<std::string>::iterator curWord;
};