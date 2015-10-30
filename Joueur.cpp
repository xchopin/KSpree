#include "Joueur.h"

// Constructeur
Joueur::Joueur(string n, int life, int v, int d) : Personnage(n,life,v,d) {
	Joueur::chargerTexture("./assets/player.png");
	m_isKeyboardUsed = false;
}

void Joueur::jouerAnimation() {
	Personnage::jouerAnimation();
	if (m_isKeyboardUsed == false) { Personnage::m_animatedSprite.stop(); }
	m_isKeyboardUsed = false;
}


void Joueur::dessinerHUD(sf::RenderWindow& window, sf::Clock& temps) {

	// Boite
	sf::RectangleShape boite(sf::Vector2f(window.getSize().x, 95));
	boite.setPosition(0, window.getSize().y - 65);
	boite.setFillColor(sf::Color(0, 0, 0));
	window.draw(boite);

	// Texte
	sf::Text texteVie;
	sf::Font font;
	if (!font.loadFromFile("./assets/arial.ttf")) { std::cout << "Erreur de chargement de la police arial.ttf" << std::endl; }
	texteVie.setFont(font);
	texteVie.setCharacterSize(16);
	texteVie.setColor(sf::Color::White);
	texteVie.setStyle(sf::Text::Bold);
	texteVie.setString("Santé: ");
	texteVie.setPosition(1, window.getSize().y - 55);
	window.draw(texteVie);

	// La vie
	sf::RectangleShape vie(sf::Vector2f( Joueur::getVie() * 2, 14));
	vie.setPosition(1, window.getSize().y - 25);
	vie.setFillColor(sf::Color(255, 0, 0));
	window.draw(vie);


	// Le temps
	sf::Text chrono;
	chrono.setFont(font);
	chrono.setCharacterSize(15);
	chrono.setColor(sf::Color::White);
	chrono.setStyle(sf::Text::Bold);
	int time = int(temps.getElapsedTime().asSeconds());
	int minutes = time / 60;
	int secondes = time;
	if (secondes >= 60) {
		int retirer = 60 * minutes;
		secondes = time - retirer;
	}


	chrono.setString(to_string(minutes) + " : " + to_string(secondes));
	chrono.setPosition(window.getSize().x / 2, window.getSize().y - 30);
	window.draw(chrono);


}

void Joueur::clavier() {

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
		if ((Joueur::getY() + Joueur::getVitesse()) <= 590) {
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
