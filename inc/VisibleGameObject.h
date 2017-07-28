#ifndef INC_VISIBLEGAMEOBJECT_H
#define INC_VISIBLEGAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "gameobject.h"

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load( std::string filename );
	virtual void Draw( sf::RenderWindow & window );

	virtual void SetPosition( float x, float y );
private:
	sf::Sprite _sprite;
	sf::Texture texture;
	std::string _filename;
	bool _isLoaded;
};

#endif
