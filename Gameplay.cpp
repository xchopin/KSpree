#include "Gameplay.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Gameplay {

public:
	Gameplay()
	{
	}


	void creerCurseur(sf::RenderWindow& window, int largeurCurseur) {
		window.setMouseCursorVisible(false);
		sf::View fixed = window.getView();
		sf::Texture texture;
		texture.loadFromFile("./assets/crosshair.png");
		sf::Sprite sprite(texture);
		sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.setView(fixed);
		window.draw(sprite);
	}




};

