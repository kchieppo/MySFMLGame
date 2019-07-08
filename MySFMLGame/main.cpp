#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include "Character.h"
#include "DialogueBox.h"
#include "TitleScreen.h"
#include "GameState.h"
#include "Room.h"

// TODO: fix vibrating sprite

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "False Vacuum",
		sf::Style::Titlebar | sf::Style::Close);
	window.setActive(true);
	window.setVerticalSyncEnabled(true);
	// Init game state machine
	GameState gameState = GameState::TitleScreen;
	// Title screen
	TitleScreen tScreen;
	// Load first room
	Room room(64, 64);
	// Load main character sprite to display
	Character boy({ 0.0f, 0.0f });
	// Menu
	std::string dialogueMsg = "Man, what the hell? There is nothing "
		"here I guess. I love my mom. Mom is the best mom.";
	DialogueBox dialogueBox(dialogueMsg);
	// timepoint for dt measurement
	auto tp = std::chrono::steady_clock::now();

	// Start the game loop
	bool running = true;
	bool titleScreen = true;
	bool gameIsPaused = false;
	bool dialogueOnce = true;
	bool once = true;
	while (running)
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// Close window: exit
			case sf::Event::Closed:
				running = false;
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
			{
				tScreen.draw(window);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					gameState = GameState::GameScreen;

				// Update the window
				window.display();
				break;
			}
			case GameState::GameScreen:
			{
				// handle movement input
				sf::Vector2f dir = { 0.0f, 0.0f };
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					dir.y -= 1.0f;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					dir.y += 1.0f;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					dir.x -= 1.0f;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					dir.x += 1.0f;
				}
				boy.setDirection(dir);

				boy.update(dt);

				window.clear();

				// Draw the room
				room.draw(window);
				// Draw the sprite
				boy.draw(window);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					gameState = GameState::MainMenuScreen;
				// Update the window
				window.display();
				break;
			}
			case GameState::MainMenuScreen:
			{
				// Draw DialogueBox and update the window
				if (dialogueOnce)
				{
					dialogueBox.drawAndDisplay(window);
					dialogueOnce = false;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					gameState = GameState::GameScreen;
					dialogueOnce = true;
				}
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}