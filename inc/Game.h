#ifndef INC_GAME_H
#define INC_GAME_H
#include <SFML/Graphics.hpp>


class Game
{
public:
	static void Start();
private:
	static bool isExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState{ Uninitialized, ShowingSplash, Paused, ShowingMenu,
			Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

#endif
