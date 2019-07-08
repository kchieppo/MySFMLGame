#include "DialogueBox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <regex>
#include <thread>
#include <chrono>

DialogueBox::DialogueBox(std::string& message)
	:
	rectangleShape({ diagBoxWidth, diagBoxHeight })
{
	rectangleShape.setPosition({ diagBoxXLoc, diagBoxYLoc });
	rectangleShape.setOutlineColor({ 0, 0, 255 });
	rectangleShape.setOutlineThickness(5.0f);

	font.loadFromFile("Sprites/Fonts/p052l-bold.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Red);
	text.setPosition({ diagBoxXLoc, diagBoxYLoc });

	tokenize(message);
}

void DialogueBox::tokenize(std::string& message)
{
	std::regex reg_exp{ R"([\s]+)" };
	std::sregex_token_iterator end_tokens;
	std::sregex_token_iterator it{ message.begin(), message.end(), reg_exp, -1 };
	while (it != end_tokens)
		tokenizedMessage.emplace_back(*it++);
}

void DialogueBox::drawAndDisplay(sf::RenderWindow& rw)
{
	rw.draw(rectangleShape);
	rw.display();

	float totalWidthOfLine = lineWidthPadding;
	float totalHeightOfLines = 0.0f;

	text.setString(" ");
	float widthOfSpace = text.getLocalBounds().width;

	for (std::vector<std::string>::iterator it = tokenizedMessage.begin();
		it != tokenizedMessage.end(); ++it)
	{
		std::string word = *it + " ";
		text.setString(word);

		float potentialWidthOfLine = totalWidthOfLine + text.getLocalBounds().width;
		if (potentialWidthOfLine > diagBoxWidth - lineWidthPadding)
		{
			// try without space
			word.pop_back();
			text.setString(word);
			potentialWidthOfLine -= widthOfSpace;
			if (potentialWidthOfLine > diagBoxWidth - lineWidthPadding)
			{
				float potentialHeightOfLines = totalHeightOfLines +
					text.getLocalBounds().height + lineHeightPadding;
				// prepare text object only if room for another line
				if (potentialHeightOfLines <= diagBoxHeight - text.getLocalBounds().height)
				{
					totalHeightOfLines = potentialHeightOfLines;

					text.setPosition({ diagBoxXLoc + lineWidthPadding, diagBoxYLoc + totalHeightOfLines });
					word = *it + " ";
					text.setString(word);
					rw.draw(text);
					rw.display();
					totalWidthOfLine = lineWidthPadding + text.getLocalBounds().width;
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}
				else
				{
					// button press to clear text
				}
			}
			else
			{
				text.setPosition({ diagBoxXLoc + totalWidthOfLine, diagBoxYLoc + totalHeightOfLines });
				totalWidthOfLine = lineWidthPadding;
				rw.draw(text);
				rw.display();
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
		}
		else // update current line
		{
			text.setPosition({ diagBoxXLoc + totalWidthOfLine, diagBoxYLoc + totalHeightOfLines });

			rw.draw(text);
			rw.display();
			totalWidthOfLine = potentialWidthOfLine;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	}
}
