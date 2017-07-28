#ifndef INC_SPLASHSCREEN_H
#define INC_SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
class SplashScreen
{
public:
	void Show( sf::RenderWindow & window );
private:
	sf::Texture texture;
};

#endif
