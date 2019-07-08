#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class DialogueBox
{
public:
	DialogueBox(std::string& message);
	void drawAndDisplay(sf::RenderWindow& rw);
private:
	void tokenize(std::string& message);
private:
	static constexpr float diagBoxXLoc = 200.0f;
	static constexpr float diagBoxYLoc = 450.0f;
	static constexpr float diagBoxWidth = 400.0f;
	static constexpr float diagBoxHeight = 100.0f;
	static constexpr float lineWidthPadding = 5.0f;
	static constexpr float lineHeightPadding = 5.0f;
	sf::RectangleShape rectangleShape;
	sf::Font font;
	sf::Text text;
	std::vector<std::string> tokenizedMessage;
};