
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Personnage.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>
#include "HUD.cpp"


class Gameplay {
public:

	static void Gameplay::creerCurseur(sf::RenderWindow& window, int largeurCurseur) {
		window.setMouseCursorVisible(false);
		sf::View fixed = window.getView();
		sf::Texture texture;
		texture.loadFromFile("./assets/crosshair.png");
		sf::Sprite sprite(texture);
		sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.setView(fixed);
		window.draw(sprite);
	}

	bool Gameplay::isOnZombie( sf::RenderWindow& window, Joueur j ,Zombie z) {
		sf::Vector2i curseur = sf::Mouse::getPosition(window);
		bool res = false;
	
		
			if ((z.getX() >= curseur.x - 10 && z.getX() <= curseur.x + 10) 
				&& z.getY() >= curseur.y - 10 && z.getY() <= curseur.y + 10)  {
				res = true;
				HUD::afficherInfoZombie(window, z);
		

		}
		return res;
	}


	void Gameplay::tirer(Joueur j, Zombie z) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
		}
	}

};





