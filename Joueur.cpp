#include "Joueur.h"

// Constructeur
Joueur::Joueur(string n, int life, int v, int d) : Personnage(n,life,v,d) {
	
	Joueur::chargerTexture("./assets/player.png");
	m_isKeyboardUsed = false;
	m_kill = 0;
}

void Joueur::jouerAnimation() {
	Personnage::jouerAnimation();
	if (m_isKeyboardUsed == false) { Personnage::m_animatedSprite.stop(); }
	m_isKeyboardUsed = false;
}



void Joueur::clavier() {
	sf::sleep(sf::milliseconds(1));
	//  Axe X 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

		if (( Joueur::getX() - Joueur::getVitesse()) >= 0) {
			this->setX(this->getX() - this->getVitesse());
			m_animationActuel = &m_animationMarcherGauche;
			m_isKeyboardUsed = true;
		}

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		if ((Joueur::getX() + Joueur::getVitesse()) <= 790) {
			Joueur::setX(Joueur::getX() + Joueur::getVitesse());
			m_animationActuel = &m_animationMarcherRight;
			m_isKeyboardUsed = true;
		}


		//  Axe Y

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if ((Joueur::getY() + Joueur::getVitesse()) <= 500) {
			Joueur::setY(Joueur::getY() + Joueur::getVitesse());
			m_animationActuel = &m_animationMarcherBas;
			m_isKeyboardUsed = true;
		}


	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

		if ((Joueur::getY() - Joueur::getVitesse()) >= 0) {

			Joueur::setY(Joueur::getY() - Joueur::getVitesse());
			m_animationActuel = &m_animationMarcherUp;
			m_isKeyboardUsed = true;

		}
	}


}
