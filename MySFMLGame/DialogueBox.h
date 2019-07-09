#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class DialogueBox
{
public:
	DialogueBox(std::string& message);
	void draw(sf::RenderTarget& rt) const;
	void update(float dt);
	void reset();
	const sf::RenderTexture& getRenderTexture();
private:
	void drawToRenderTexture();
	void tokenize(std::string& message);
	bool hasMoreWords();
private:
	static constexpr float diagBoxXLoc = 200.0f;
	static constexpr float diagBoxYLoc = 450.0f;
	static constexpr float diagBoxWidth = 400.0f;
	static constexpr float diagBoxHeight = 100.0f;
	static constexpr float lineWidthPadding = 5.0f;
	static constexpr float lineHeightPadding = 2.0f;
	static constexpr float holdTime = 0.2f;
	static constexpr float outlineThickness = 5.0f;
	float time = 0.0f;
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;
	sf::RectangleShape rectangleShape;
	sf::Font font;
	sf::Text text;
	std::vector<std::string> tokenizedMessage;
	std::vector<std::string>::iterator curWord;
};