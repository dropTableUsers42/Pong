#include "MainMenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MenuResult MainMenu :: Show( sf::RenderWindow & window )
{
	if( !texture.loadFromFile("images/Mainmenu.jpg") )
	{
		return MainMenu::Nothing;
	}
	
	sf::Sprite sprite;
	sprite.setTexture( texture );

	MenuItem playButton;
	playButton.rect.top = 94;
	playButton.rect.height = 250 - 94;
	playButton.rect.left = 0;
	playButton.rect.width = 800 - 0;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 800 - 0;
	exitButton.rect.top = 251;
	exitButton.rect.height = 369 - 251;
	exitButton.action = Exit;

	_menuItems.push_back( playButton );
	_menuItems.push_back( exitButton );

	window.draw( sprite );
	window.display();

	return GetMenuResponse( window );
}

MainMenu::MenuResult MainMenu :: HandleClick( int x, int y )
{
	std::list<MenuItem>::iterator it;
	for( it = _menuItems.begin(); it != _menuItems.end(); it++ )
	{
		sf::Rect<int> menuItemRect = it->rect;
		int top = menuItemRect.top;
		int bottom = menuItemRect.height + top;
		int left = menuItemRect.left;
		int right = menuItemRect.width + left;
		if( bottom > y
			&& top < y
			&& left < x
			&& right > x )
		{
			return it->action;
		}
	}
}

MainMenu::MenuResult MainMenu :: GetMenuResponse( sf::RenderWindow & window )
{
	sf::Event menuEvent;

	while( true )
	{
		while( window.pollEvent( menuEvent ) )
		{
			if( menuEvent.type == sf::Event::MouseButtonPressed )
			{
				return HandleClick( menuEvent.mouseButton.x, menuEvent.mouseButton.y );
			}
			if( menuEvent.type == sf::Event::Closed )
			{
				return Exit;
			}
		}
	}
}
