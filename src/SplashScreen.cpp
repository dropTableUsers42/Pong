#include <SFML/Graphics.hpp>
#include "SplashScreen.h"
#include <iostream>

void SplashScreen :: Show( sf::RenderWindow & window )
{
	if( !texture.loadFromFile( "images/SplashScreen.jpg" ) )
	{
		return;
	}
	sf::Sprite sprite;
	sprite.setTexture( texture );

	window.draw( sprite );
	window.display();

	sf::Event event;
	while( true )
	{
		while( window.pollEvent(event) )
		{
			if( event.type == sf::Event::KeyPressed
					|| event.type == sf::Event::MouseButtonPressed
					|| event.type == sf::Event::Closed )
			{
				return;
			}
		}
	}
}
