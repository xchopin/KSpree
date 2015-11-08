#include "TileMap.cpp"
#include "Zombie.h"
#include "Joueur.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>	
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
#include "Gameplay.cpp"
#include "Launcher.cpp"
#include "Personnage.h"
#include <vector>
class moteur {

public: 

	static const TileMap genererCarte() {
		const int level[] = {
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	
		};


		TileMap map;
		if (!map.load("./assets/tileset.png", sf::Vector2u(32, 32), level, 32, 32)) {
			std::cout << "impossible de charger la texture de map" << std::endl;
		}

		return map;

	}

	static const vector<Zombie> genererZombies(int round){
		int nb;
		if (round < 6) {
			nb = 4;
		} else if (round < 11 && round > 5) {
			nb = 7;
		}else{
			nb = 10;
		}

		vector<Zombie> tab;

		for (int i = 0; i < nb; i++) {
			int aleatoire =( rand() % 100) ;
			int x = (aleatoire + 50) * 3 ;
			int y = (aleatoire + 55) *4 ;
			Zombie z;
			z.chargerTexture("./assets/zombie.png");
			z.setX(y);
			z.setY(x);
			z.setDegat(z.getDegat() + round);
			z.setVie(z.getVie() + round);
			z.setVitesse(z.getVitesse() + (aleatoire / 80));
		
			tab.push_back(z);
		}

		return tab;
	}

	static const void start() {
		int choix;
		sf::Vector2i dimensionFenetre(800, 600);
		sf::RenderWindow fenetre(sf::VideoMode(dimensionFenetre.x, dimensionFenetre.y), "KSpree v0.5h");
		fenetre.setFramerateLimit(60);
		sf::Music main_theme;
		main_theme.openFromFile("./assets/main_theme.ogg");
		main_theme.play();
		while (fenetre.isOpen()) {
			sf::Event event;

			while (fenetre.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					fenetre.close();

			}


			fenetre.clear();
			choix = Launcher::afficherLauncher(fenetre);
			fenetre.display();
			if (choix == 1) {
				main_theme.stop();
				sf::sleep(sf::seconds(0.5)); // faire une sensation de chargement
				moteur::run(fenetre);
				
			}
		

		}
	}
	

	
	static const void run(sf::RenderWindow& fenetre) {
	
#pragma region variables
	
		// Personnages
		Joueur joueur("Xavier", 100, 2, 30);
	
		vector <Zombie> tab_zombie;
		//Génerer map manuellement, pas très utile pour cette version du jeu
		//TileMap carte;
		//carte = moteur::genererCarte();
		sf::Texture texture_carte;
		texture_carte.loadFromFile("./assets/carte.png");
		sf::Sprite sprite_carte(texture_carte);
		// Système du jeu
		bool pause = false;

		sf::Clock temps;
		sf::Clock horloge;
		sf::Clock horloge_rechargement;
		sf::Clock horloge2;
		bool hasShot = false;
		bool hasReload = false;
		int round = 0;

		// SFX
		sf::Music cri_zombie;
		sf::Music sfx_tir;
		sf::Music sfx_reload;
		cri_zombie.openFromFile("./assets/fuck.ogg");
		sfx_tir.openFromFile("./assets/sfx_tir.ogg");
		sfx_reload.openFromFile("./assets/sfx_reload.ogg");
		sfx_tir.setVolume(50);
		sfx_reload.setVolume(50);
#pragma endregion
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
				if (tab_zombie.size() < 1) {
					round++;
					tab_zombie = moteur::genererZombies(round);
				}

				// Animation du joueur
				joueur.jouerAnimation();
				
				joueur.clavier();
				joueur.updateAnimation(frameTime);

				// Affichage sur la fenêtre
				fenetre.clear();
				fenetre.draw(sprite_carte);


				for (int i = 0; i < tab_zombie.size(); i++) {
					tab_zombie[i].chargerTexture("./assets/zombie.png");
					tab_zombie[i].jouerAnimation();
					tab_zombie[i].m_animatedSprite.setPosition(tab_zombie[i].getX(), tab_zombie[i].getY());
					tab_zombie[i].updateAnimation(frameTime);
					fenetre.draw(tab_zombie[i].getAnimatedSprite());
					if (!tab_zombie[i].poursuivre(joueur)) {
						if (horloge2.getElapsedTime().asSeconds() >= 1) {
							cri_zombie.play();
							joueur.seFaireAttaquer(tab_zombie[i]); // quand le joueur n'est pas poursuivi on l'attaque toutes les secondes
							horloge2.restart();
							
						}
					} 
				
					if (Gameplay::isOnZombie(fenetre, joueur, tab_zombie[i])) {
						HUD::afficherInfoZombie(fenetre,tab_zombie[i]);
				
						if (!(sfx_tir.getStatus() == sf::Music::Status::Playing)) {
							if ((sf::Mouse::isButtonPressed(sf::Mouse::Button::Left ) && (joueur.getMunition() > 0))) { hasShot = true; }

							while ((hasShot == true)) {
								sfx_tir.play();
								joueur.m_munition--;
								tab_zombie[i].seFaireAttaquer(joueur);
								hasShot = false;
							}
						}

						if (tab_zombie[i].isDead()) {
							joueur.m_kill++;
							tab_zombie.erase(tab_zombie.begin() + i);
							joueur.setVie(joueur.getVie() + 2);	
							sf::sleep(sf::milliseconds(5));
						}
					}
				}
				
			
				fenetre.draw(joueur.getAnimatedSprite());
				HUD::creerCurseur(fenetre, 16);
				HUD::dessinerHUD(fenetre, horloge, joueur,round);
				//Si la le tir n'est pas joué on se permet de tirer
				if (!(sfx_tir.getStatus() == sf::Music::Status::Playing)){
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (joueur.getMunition() > 0 )) {   hasShot = true;}
					while ((hasShot == true)) {
						sfx_tir.play();
						joueur.m_munition--;
						hasShot = false;
						
					}
				
				}



				// Rechargement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					hasReload = true;
					horloge_rechargement.restart();
					sfx_reload.play();
				}

				if ((hasReload == true) && (horloge_rechargement.getElapsedTime().asSeconds() > 3)) {
					joueur.rechargerMunition();
					horloge_rechargement.restart();
					hasReload = false;
				}

				fenetre.display();
			}
		}

	}
	
};