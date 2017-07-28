#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Constants.h"

void Game :: Start()
{
	if( _gameState != Uninitialized )
		return;

	_mainWindow.create(sf::VideoMode(GWidth,GHeight),"Pong");

	_gameState = Game:: ShowingSplash;

	while(!isExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game :: isExiting()
{
	if( _gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game :: GameLoop()
{
	switch( _gameState )
	{
		case Game::Playing:
		{
			sf::Event currentEvent;
			while( _mainWindow.pollEvent(currentEvent) )
			{
				_mainWindow.clear( sf::Color(255,0,0) );
				_mainWindow.display();

				if( currentEvent.type == sf::Event::Closed )
				{
					_gameState = Game::Exiting;
				}

				if( currentEvent.type == sf::Event::KeyPressed )
				{
					if( currentEvent.key.code == sf::Keyboard::Escape )
						ShowMenu();
				}
				break;
			}
		}
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
	}
}

void Game :: ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game :: ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show( _mainWindow );
	switch( result )
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
