#include <SFML/Graphics.hpp>
#include "VisibleGameObject.h"

VisibleGameObject :: VisibleGameObject()
{
	_isLoaded = false;
}

VisibleGameObject :: ~VisibleGameObject()
{
}

void VisibleGameObject :: Load( std::string filename )
{
	if( texture.loadFromFile(filename) == false )
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture( texture );
		_isLoaded = true;
	}
}

void VisibleGameObject :: Draw( sf::RenderWindow & window )
{
	if( _isLoaded )
	{
		window.draw( _sprite );
	}
}

void VisibleGameObject :: SetPosition( float x, float y )
{
	if( _isLoaded )
	{
		_sprite.setPosition( x,y );
	}
}
