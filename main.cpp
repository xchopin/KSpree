#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>
#include "Personnage.cpp"
#include "Animation.hpp"
#include "TileMap.cpp"
#include "Gameplay.cpp"

#include <vector>

#pragma region variables

//Mod�le
Personnage joueur("Joueur 1", 100, 10, 10);
sf::Vector2f mouvement(0.f, 0.f);

//Vue

//Controller 
Gameplay control;

// Syst�me du jeu
sf::Clock temps;
sf::Vector2i dimensionFenetre(800, 600);
sf::RenderWindow fenetre(sf::VideoMode(dimensionFenetre.x, dimensionFenetre.y), "Killing spree");
sf::RenderWindow *fenetre2;
#pragma endregion


int main(){

	// Param�tres de la fen�tre
	
	fenetre.setFramerateLimit(60);


	
	// Initialisation de la map


	// on d�finit le niveau � l'aide de num�ro de tuiles
	const int level[] = {
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};

	// on cr�e la tilemap avec le niveau pr�c�demment d�fini
	TileMap map;
	if (!map.load("./assets/tileset.png", sf::Vector2u(32, 32), level, 32, 32)) {
		cout << "impossible de charger la texture de map" << endl;
	}

	
		while (fenetre.isOpen()) {

		sf::Event event;
		while (fenetre.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				fenetre.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				fenetre.close();
		}
		 
		sf::Time frameTime = temps.restart();


		// Animation du joueur
		joueur.jouerAnimation();
		joueur.controller();
		joueur.updateAnimation(frameTime);

		// Affichage sur la fen�tre
		fenetre.clear();
		fenetre.draw(map);
		fenetre.draw(joueur.getAnimatedSprite());
		control.creerCurseur(fenetre, 16);
		fenetre.display();
	}

	return 0;
}



