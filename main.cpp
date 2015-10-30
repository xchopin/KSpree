#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>	
#include "AnimatedSprite.hpp"
#include <iostream>
#include "Animation.hpp"
#include "moteur.cpp"
#include "Gameplay.cpp"
#include "Personnage.h"
#include "Joueur.h"
#include "Zombie.h"
#include <vector>

#pragma region variables

//Modèle
Joueur joueur("Xavier", 100, 2 ,10);
vector<Zombie> tabZombies;

//Vue

//Controller 
Gameplay control;

// Système du jeu
sf::Clock temps;
sf::Clock horloge;
sf::Clock horloge2;
sf::Vector2i dimensionFenetre(800, 600);
sf::RenderWindow fenetre(sf::VideoMode(dimensionFenetre.x, dimensionFenetre.y), "Killing spree v0.1");
Zombie zombietest;
#pragma endregion

vector <Zombie> tab = moteur::genererZombies();

//Musique

sf::Music cri_zombie;
sf::Music sfx_tir;



int main(){
	sfx_tir.setVolume(50);
	cri_zombie.openFromFile("./assets/fuck.ogg");
	sfx_tir.openFromFile("./assets/sfx_tir.ogg");

	// Paramètres de la fenêtre
	
	fenetre.setFramerateLimit(60);

	
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

			// Affichage sur la fenêtre
			fenetre.clear();
			fenetre.draw(moteur::genererCarte());
			joueur.dessinerHUD(fenetre, horloge);
			
				for (int i = 0; i < tab.size(); i++) {
					tab[i].chargerTexture("./assets/zombie.png");
					tab[i].jouerAnimation();
					tab[i].m_animatedSprite.setPosition(tab[i].getX(), tab[i].getY());
					tab[i].updateAnimation(frameTime);
					fenetre.draw(tab[i].getAnimatedSprite());

					if (!tab[i].poursuivre(joueur)) {
						if (horloge2.getElapsedTime().asSeconds() >= 1) {
							cri_zombie.play();

							joueur.seFaireAttaquer(tab[i]); // quand le joueur n'est pas poursuivi on l'attaque toutes les secondes
							horloge2.restart();
						}
					} // si le joueur n'est pas poursuivi ;)
					if (control.isOnZombie(fenetre, joueur, tab[i])) {

						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


							tab[i].seFaireAttaquer(joueur);
							if (tab[i].isDead()) {
								tab.erase(tab.begin() + i);
							}
						}


					}

				}

				//zombietest.jouerAnimation();
				//.updateAnimation(frameTime);
				//zombietest.poursuivre(joueur);
				//fenetre.draw(zombietest.getAnimatedSprite());
				fenetre.draw(joueur.getAnimatedSprite());

				Gameplay::creerCurseur(fenetre, 16);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sfx_tir.play();
				}



				fenetre.display();
			}
		
	}

	return 0;
}



