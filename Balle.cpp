#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <vector>
#include <iostream>



using namespace std;

// Classe spéciale à utiliser pour plus tard, permet l'animation des balles, trop de bug pour l'instant ahah ^^ 

class Balle {
private :
	sf::Vector2i objectif;
	sf::Vector2i coordonnees;

public: 

	Balle(sf::Vector2i c) {
		this->coordonnees = c;
	}


	// -- - - -- - - - Méthodes - - -- - - -//

	// GUI

	void dessinerBalle (sf::RenderWindow& window) {
		sf::RectangleShape sprite(sf::Vector2f(10, 10));
		
		
		this->setCoordonnees(sf::Vector2i(this->getCoordonnees().x+1, this->getCoordonnees().y));
		sprite.setPosition(this->getCoordonnees().x, this->getCoordonnees().y);
		cout << " x: "<< to_string(this->getCoordonnees().x) << endl;
		window.draw(sprite);
	}


	void atteindreObjectif(sf::RenderWindow& window) {
	
		//this->deplacerVersObjectif();
		
		this->dessinerBalle(window);
		
		/**if (this->coordonnees != this->objectif) {
			this->atteindreObjectif(window);
		}*/
	}



	// Méthode permettant de se DEPLACER vers l'objectif et NON D'ATTEINDRE DIRECTEMENT L'OBJECTIF
	void deplacerVersObjectif() {

		if (coordonnees.x < objectif.x) {
			this->setCoordonnees(sf::Vector2i(this->getCoordonnees().x + 1, this->getCoordonnees().y));
		}

		else if (coordonnees.x > objectif.x) {
			this->setCoordonnees(sf::Vector2i(this->getCoordonnees().x - 1, this->getCoordonnees().y));
		}

		if (coordonnees.y < objectif.y) {
			this->setCoordonnees(sf::Vector2i(this->getCoordonnees().x, this->getCoordonnees().y + 1));
		}

		else if (coordonnees.y > objectif.y) {
			this->setCoordonnees(sf::Vector2i(this->getCoordonnees().x, this->getCoordonnees().y - 1));
		}

	}


	// Getter - Setter

	void setObjectif(sf::Vector2i o) {
		this->objectif = o;
	}

	sf::Vector2i getObjectif() {
		return this->objectif;
	}


	void setCoordonnees(sf::Vector2i& c) {
		this->coordonnees = c;
	}


	sf::Vector2i getCoordonnees() {
		return this->coordonnees;
	}


};