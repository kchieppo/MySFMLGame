#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include "MainCharacter.h"
#include "DemonCharacter.h"
#include "DialogueBox.h"
#include "TitleScreen.h"
#include "GameState.h"
#include "WorldMap.h"
#include "Constants.h"

// TODO: fix vibrating sprite

int main()
{
	// Create the main window
	sf::RenderWindow window(
		sf::VideoMode
      (Constants::WINDOW_WIDTH_PIXELS, Constants::WINDOW_HEIGHT_PIXELS),
      "False Vacuum", sf::Style::Titlebar | sf::Style::Close
   );
	window.setActive(true);
	window.setVerticalSyncEnabled(true);
	// Init game state machine
	GameState gameState = GameState::TitleScreen;
	// Title screen
	TitleScreen tScreen;
	// Load world map
	WorldMap worldMap;
	MainCharacter* const mainCharacterPtr = worldMap.getMainCharacterPtr();

	sf::Vector2f walkDir;
	// Menu
	std::string dialogueMsg = "This is a long message. A really, really long "
      "message. Why did I write such a long message? It's because I wanted to "
      "test out my dialogue box. By the way, I love you.";
	DialogueBox dialogueBox(dialogueMsg);
	// timepoint for dt measurement
	auto tp = std::chrono::steady_clock::now();

	bool titleScreen = true;
	bool gameIsPaused = false;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// Close window: exit
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		// get dt
		float dt;
		{
			const auto new_tp = std::chrono::steady_clock::now();
			dt = std::chrono::duration<float>(new_tp - tp).count();
			tp = new_tp;
		}

		switch (gameState)
		{
			case GameState::TitleScreen:
				window.clear();
				tScreen.draw(window);
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					gameState = GameState::GameScreen;
				break;
			case GameState::GameScreen:
				walkDir = { 0.0f, 0.0f };
				if (mainCharacterPtr->getAabbMax().y < 0 && worldMap.up())
					mainCharacterPtr->setPositionY
               (
                  static_cast<float>(Constants::WINDOW_HEIGHT_PIXELS
						- mainCharacterPtr->getSpriteHeight())
               );
				else if (mainCharacterPtr->getAabbMin().y
               > Constants::WINDOW_HEIGHT_PIXELS && worldMap.down())
					mainCharacterPtr->setPositionY(0);
				else if (mainCharacterPtr->getAabbMin().x < 0 && worldMap.left())
					mainCharacterPtr->setPositionX
               (
                  static_cast<float>(Constants::WINDOW_WIDTH_PIXELS
						- mainCharacterPtr->getSpriteWidth())
               );
				else if (mainCharacterPtr->getAabbMax().x
               > Constants::WINDOW_WIDTH_PIXELS && worldMap.right())
					mainCharacterPtr->setPositionX(0);
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						walkDir.y -= 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						walkDir.y += 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						walkDir.x -= 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						walkDir.x += 1.0f;
				}
				mainCharacterPtr->setAnimationIndex(walkDir);

				worldMap.updateCurrentRoom(dt);
				mainCharacterPtr->update(dt);

				worldMap.adjustForCollisionsWithRoom();

				window.clear();
				worldMap.handleRoomDrawing(window);
				mainCharacterPtr->draw(window);
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					gameState = GameState::MainMenuScreen;
				break;
			case GameState::MainMenuScreen:
				dialogueBox.update(dt);

				window.clear();
				worldMap.handleRoomDrawing(window);
				mainCharacterPtr->draw(window);
				dialogueBox.draw(window);
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					gameState = GameState::GameScreen;
					dialogueBox.reset();
				}
				break;
		}
	}
	return EXIT_SUCCESS;
}
