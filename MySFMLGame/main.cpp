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
#include "Audio.h"

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
	window.setPosition({ window.getPosition().x + 450,
		window.getPosition().y + 125 });
	// Init audio
	Audio audio;
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

	audio.playMusic();

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
				{
					gameState = GameState::GameScreen;
					audio.stopMusic();
				}
				break;
			case GameState::GameScreen:
				walkDir = { 0.0f, 0.0f };
				if (worldMap.roomIsTranslating() == false)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						walkDir.y -= 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						walkDir.y += 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						walkDir.x -= 1.0f;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						walkDir.x += 1.0f;
					if (walkDir.x != 0 && walkDir.y != 0)
					{
						walkDir.x = walkDir.x / std::abs(walkDir.x) / Constants::SQRT_2_APPROX;
						walkDir.y = walkDir.y / std::abs(walkDir.y) / Constants::SQRT_2_APPROX;
					}
					worldMap.updateCurrentRoom(dt);
					worldMap.adjustForCollisionsWithRoom();

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
						gameState = GameState::MainMenuScreen;
				}
				mainCharacterPtr->setVelocity(walkDir);
				mainCharacterPtr->setAnimationIndex(walkDir);
				mainCharacterPtr->update(dt);

				window.clear();
				worldMap.handleRoomDrawing(window);
				mainCharacterPtr->draw(window);
				window.display();

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
