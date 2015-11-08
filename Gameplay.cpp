#ifndef DEF_GAMEPLAY
#define DEF_GAMEPLAY
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Personnage.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>

#include "HUD.cpp"
class Gameplay {
public:

	static bool Gameplay::isOnZombie(sf::RenderWindow& window, Joueur j, Zombie z) {
		sf::Vector2i curseur = sf::Mouse::getPosition(window);
		bool res = false;


		if ((z.getX() >= curseur.x - 13 && z.getX() <= curseur.x + 13)
			&& z.getY() >= curseur.y - 25 && z.getY() <= curseur.y + 8) {
			res = true;
			HUD::afficherInfoZombie(window, z);


		}
		return res;
	}

};

#endif



