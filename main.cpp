 #include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>
#include "Animation.hpp"
#include "TileMap.cpp"
#include "Gameplay.cpp"
#include "Personnage.h"
#include "Joueur.h"

#include <vector>

#pragma region variables

//Modèle
Joueur joueur("Xavier", 100, 2 ,10);
//vector<Personnage> tabZombies;

//Vue

//Controller 
Gameplay control;

// Système du jeu
sf::Clock temps;
sf::Clock horloge;
sf::Vector2i dimensionFenetre(800, 600);
sf::RenderWindow fenetre(sf::VideoMode(dimensionFenetre.x, dimensionFenetre.y), "Killing spree");
#pragma endregion




int main(){

	// Paramètres de la fenêtre
	
	fenetre.setFramerateLimit(60);

	//Création rapide du tableau de mob pour les tests ;)
/*
	Zombie z1;
	Zombie z2;
	z2.setX(150);

	tabZombies.push_back(z1);
	tabZombies.push_back(z2);*/
	// Initialisation de la map


	// on définit le niveau à l'aide de numéro de tuiles
	const int level[] = {
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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

	// on crée la tilemap avec le niveau précédemment défini
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
		 
		if (event.type != sf::Event::LostFocus) {
			sf::Time frameTime = temps.restart();


			// Animation du joueur
			joueur.jouerAnimation();
			joueur.clavier();
			joueur.updateAnimation(frameTime);

			//animation des zombies
		
			// Controller
			


			// Affichage sur la fenêtre
			fenetre.clear();
			fenetre.draw(map);

		
	
			fenetre.draw(joueur.getAnimatedSprite());
			joueur.dessinerHUD(fenetre,horloge);
			Gameplay::creerCurseur(fenetre, 16);
			//control.isOnEnnemie(tabZombies, fenetre);
			sf::Vector2i curseur = sf::Mouse::getPosition(fenetre);
		/**	for (int i = 0; i < tabZombies.size(); i++) {
				if (tabZombies[i].getX() >= curseur.x - 10 && tabZombies[i].getX() <= curseur.x + 10) {
					cout << "LEL" << endl;
				}
			}*/

			//
			
			fenetre.display();
		}
	}

	return 0;
}



