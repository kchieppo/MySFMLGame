#include "DialogueBox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <regex>
#include <thread>
#include <chrono>

DialogueBox::DialogueBox(std::string& message)
	:
	rectangleShape({ diagBoxWidth - 2*outlineThickness,
		diagBoxHeight - 2*outlineThickness })
{
	renderTexture.create(int(diagBoxWidth), int(diagBoxHeight));
	sprite.setPosition({ diagBoxXLoc, diagBoxYLoc });

	rectangleShape.setPosition({ outlineThickness, outlineThickness });
	rectangleShape.setOutlineColor({ 0, 0, 255 });
	rectangleShape.setOutlineThickness(outlineThickness);

	font.loadFromFile("Sprites/Fonts/p052l-bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString(" ");
	text.setFillColor(sf::Color::Black);
	//text.setPosition({ diagBoxXLoc, diagBoxYLoc });

	tokenize(message);
	curWord = tokenizedMessage.begin() + 1;
}

void DialogueBox::tokenize(std::string& message)
{
	std::regex reg_exp{ R"([\s]+)" };
	std::sregex_token_iterator end_tokens;
	std::sregex_token_iterator it{ message.begin(), message.end(), reg_exp, -1 };
	while (it != end_tokens)
		tokenizedMessage.emplace_back(*it++);
}

void DialogueBox::draw(sf::RenderTarget& rt) const
{
	rt.draw(sprite);
}

// TODO: use memoization here?
void DialogueBox::drawToRenderTexture()
{
	renderTexture.clear();
	renderTexture.draw(rectangleShape);

	float totalWidthOfLine = outlineThickness + lineWidthPadding;
	float totalHeightOfLines = outlineThickness;

	text.setString(" ");
	float widthOfSpace = text.getLocalBounds().width;

	for (std::vector<std::string>::iterator it = tokenizedMessage.begin();
		it != curWord; ++it)
	{
		std::string word = *it + " ";
		text.setString(word);

		float potentialWidthOfLine = totalWidthOfLine + text.getLocalBounds().width;
		if (potentialWidthOfLine > diagBoxWidth - outlineThickness - lineWidthPadding)
		{
			// try without space
			word.pop_back();
			text.setString(word);
			potentialWidthOfLine -= widthOfSpace;
			if (potentialWidthOfLine > diagBoxWidth - outlineThickness - lineWidthPadding)
			{
				float potentialHeightOfLines = totalHeightOfLines +
					text.getLocalBounds().height + lineHeightPadding;
				// prepare text object only if room for another line
				if (potentialHeightOfLines <= diagBoxHeight - outlineThickness
					- text.getLocalBounds().height)
				{
					totalHeightOfLines = potentialHeightOfLines;

					text.setPosition({ outlineThickness + lineWidthPadding, totalHeightOfLines });
					word = *it + " ";
					text.setString(word);
					renderTexture.draw(text);
					totalWidthOfLine = outlineThickness + lineWidthPadding
						+ text.getLocalBounds().width;
				}
				else
				{
					// button press to clear text
				}
			}
			else
			{
				text.setPosition({ totalWidthOfLine, totalHeightOfLines });
				// reset width of line for new line
				totalWidthOfLine = outlineThickness + lineWidthPadding;
				renderTexture.draw(text);
			}
		}
		else // update current line
		{
			text.setPosition({ totalWidthOfLine, totalHeightOfLines });

			renderTexture.draw(text);
			totalWidthOfLine = potentialWidthOfLine;
		}
	}

	if (curWord != tokenizedMessage.end())
		curWord++;

	renderTexture.display();
	sprite.setTexture(renderTexture.getTexture());
}

void DialogueBox::update(float dt)
{
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime;
		if (hasMoreWords())
			drawToRenderTexture();
	}
}

void DialogueBox::reset()
{
	curWord = tokenizedMessage.begin() + 1;
	time = 0;
	renderTexture.clear();
	renderTexture.draw(rectangleShape);
	renderTexture.display();
}

bool DialogueBox::hasMoreWords()
{
	if (curWord != tokenizedMessage.end() + 1)
		return true;
	else
		return false;
}

const sf::RenderTexture& DialogueBox::getRenderTexture()
{
	return renderTexture;
}
