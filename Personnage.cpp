#include "Personnage.h"
#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

#include "Animation.hpp"

#include <vector>

using namespace std;

class Personnage {

private:

	string nom;
	int vie;
	int degat;
	int alcoolemie;
	int vitesse;
	int x;
	int y;

public:
	bool isKeyboardUsed;


	// Variable GUI

	Animation animationMarcherBas;
	Animation animationMarcherGauche;
	Animation animationMarcherRight;
	Animation animationMarcherUp;
	Animation* animationActuel = &animationMarcherBas;
	sf::Texture textureJoueur;
	AnimatedSprite animatedSprite;
	//sf::Vector2f mouvement(0.f, 0.f);




	// - - - Constructeur - - -

	Personnage(string n, int v, int d, int a) {
		this->nom = n;
		this->vie = v;
		this->degat = d;
		this->alcoolemie = a;
		this->vitesse = 2;
		this->x = 0;
		this->y = 0;
		isKeyboardUsed = false ;

		// Chargement des textures

		if (!textureJoueur.loadFromFile("./assets/player.png"))
		{
			std::cout << "Failed to load player spritesheet!" << std::endl;
		}

		animationMarcherBas.setSpriteSheet(textureJoueur);
		animationMarcherBas.addFrame(sf::IntRect(32, 0, 32, 32));
		animationMarcherBas.addFrame(sf::IntRect(64, 0, 32, 32));
		animationMarcherBas.addFrame(sf::IntRect(32, 0, 32, 32));
		animationMarcherBas.addFrame(sf::IntRect(0, 0, 32, 32));

		animationMarcherGauche.setSpriteSheet(textureJoueur);
		animationMarcherGauche.addFrame(sf::IntRect(32, 32, 32, 32));
		animationMarcherGauche.addFrame(sf::IntRect(64, 32, 32, 32));
		animationMarcherGauche.addFrame(sf::IntRect(32, 32, 32, 32));
		animationMarcherGauche.addFrame(sf::IntRect(0, 32, 32, 32));

		animationMarcherRight.setSpriteSheet(textureJoueur);
		animationMarcherRight.addFrame(sf::IntRect(32, 64, 32, 32));
		animationMarcherRight.addFrame(sf::IntRect(64, 64, 32, 32));
		animationMarcherRight.addFrame(sf::IntRect(32, 64, 32, 32));
		animationMarcherRight.addFrame(sf::IntRect(0, 64, 32, 32));

		animationMarcherUp.setSpriteSheet(textureJoueur);
		animationMarcherUp.addFrame(sf::IntRect(32, 96, 32, 32));
		animationMarcherUp.addFrame(sf::IntRect(64, 96, 32, 32));
		animationMarcherUp.addFrame(sf::IntRect(32, 96, 32, 32));
		animationMarcherUp.addFrame(sf::IntRect(0, 96, 32, 32));

		AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
		animatedSprite.setPosition(sf::Vector2f(400, 100));
	};




	
	// - - - Getter - - -

	int getVie() { return vie; }
	int getDegat() { return degat; }
	int getVitesse() { return vitesse; }
	int getAlcoolemie() { return alcoolemie; }
	int getX() { return x; }
	int getY() { return y; }
	string getNom() { return nom; }

	// - - - Setter - - -

	void setVie(int v) { this->vie = v; }
	void setDegat(int d) { this->degat = d; }
	void setVitesse(int v) { this->vitesse = v; }
	void setAlcoolemie(int a) { this->alcoolemie = a; }
	void setNom(string n) { this->nom = n; }
	void setX(int x2) { this->x = x2; }
	void setY(int a) { this->y = a; }

	// - - - Méthodes de jeu - - -

	void perdreVie(int x) {
		if (this->getVie() - x > 0) {
			this->setVie(this->vie - x);
		}
		else {
			this->setVie(0);
		}
	}

	void attaquer(Personnage p) {
		p.perdreVie(this->getDegat());
	}


	// - - - Méthodes sur l'état du personnage - - -

	bool isDrunk() {
		if (this->getAlcoolemie() > 50) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isDead() {
		if (this->vie < 1) {
			return true;
		}
		else {
			return false;
		}

	}


	// - - - - - Méthodes GUI - - - /
	void jouerAnimation() {

		animatedSprite.play(*animationActuel);
		animatedSprite.setPosition(this->getX(), this->getY());
		// if no key was pressed stop the animation
		if (isKeyboardUsed == false)
		{
			animatedSprite.stop();
		}
		isKeyboardUsed = false;

	}

	void updateAnimation(sf::Time frameTime) {
		animatedSprite.update(frameTime);
	}


	AnimatedSprite getAnimatedSprite() {
		return this->animatedSprite;
	}



	// Méthode qui gère le clavier et la souris

	void controller() {
		//Clavier
		//  Axe X 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

			if ((this->getX() - this->getVitesse()) >= 0) {
				this->setX(this->getX() - this->getVitesse());
				animationActuel = &animationMarcherGauche;
				cout << this->getX() << endl;
				isKeyboardUsed = true;

			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if ((this->getX() + this->getVitesse()) <= 790) {
				this->setX(this->getX() + this->getVitesse());
				animationActuel = &animationMarcherRight;
				cout << this->getX() << endl;
				isKeyboardUsed = true;
			}
		}

		//  Axe Y 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			if ((this->getY() + this->getVitesse()) <= 590) {
				this->setY(this->getY() + this->getVitesse());
				animationActuel = &animationMarcherBas;
				isKeyboardUsed = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

			if ((this->getY() - this->getVitesse()) >= 0) {
				this->setY(this->getY() - this->getVitesse());
				animationActuel = &animationMarcherUp;
				isKeyboardUsed = true;

			}
		}



		// Souris

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// quelque chose ;)
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			// quelque chose ;)
		}
	}


};