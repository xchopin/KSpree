#include <iostream>
#include <string>
#include "Joueur.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>
class HUD{
public:

	void static creerCurseur(sf::RenderWindow& window, int largeurCurseur) {
		window.setMouseCursorVisible(false);
		sf::View fixed = window.getView();
		sf::Texture texture;
		texture.loadFromFile("./assets/crosshair.png");
		sf::Sprite sprite(texture);
		sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.setView(fixed);
		window.draw(sprite);
	}

	void static dessinerHUD(sf::RenderWindow& window, sf::Clock& temps, Joueur j,int manche) {
		
		// Boite
		sf::RectangleShape boite(sf::Vector2f(window.getSize().x -60, 70));
		boite.setPosition(0, window.getSize().y - 65);
		boite.setFillColor(sf::Color(0, 0, 0));
		window.draw(boite);

		// Texte
		sf::Text kill;
		sf::Text round;
		sf::Text texteVie;
		sf::Font font;
		if (!font.loadFromFile("./assets/arial.ttf")) { std::cout << "Erreur de chargement de la police arial.ttf" << std::endl; }
		texteVie.setFont(font);
		texteVie.setCharacterSize(16);
		texteVie.setColor(sf::Color::White);
		texteVie.setStyle(sf::Text::Bold);
		texteVie.setString("Santé: ");
		texteVie.setPosition(60, window.getSize().y - 68);
		window.draw(texteVie);

		kill.setFont(font);
		kill.setCharacterSize(12);
		kill.setColor(sf::Color::Red);
		kill.setStyle(sf::Text::Bold);
		kill.setString("KILLS: " + to_string(j.m_kill));
		kill.setPosition(window.getSize().x / 2 - 30, 1);
		window.draw(kill);

		// Manche 

		round.setFont(font);
		round.setCharacterSize(14);
		round.setColor(sf::Color::Red);
		round.setStyle(sf::Text::Bold);
		round.setString("MANCHE: " + to_string(manche));
		round.setPosition(window.getSize().x / 2 - 30, window.getSize().y - 60);
		window.draw(round);

		// La vie
		sf::RectangleShape vie(sf::Vector2f(j.getVie() * 1.5, 7));
		vie.setPosition(32, window.getSize().y - 35);
		vie.setFillColor(sf::Color(255, 0, 0));
		window.draw(vie);


		// image

		sf::Texture texture_joueur;
		texture_joueur.loadFromFile("./assets/player_face.png");
		sf::Sprite sprite_joueur(texture_joueur);
		sprite_joueur.setPosition(7, window.getSize().y - 50);
		
		window.draw(sprite_joueur);

	

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
		chrono.setPosition(window.getSize().x / 2, window.getSize().y - 25);
		window.draw(chrono);


	}

	void static afficherInfoZombie(sf::RenderWindow& window,Zombie zomb) {
	sf::View fixed = window.getView();
	sf::Texture texture;
	texture.loadFromFile("./assets/zombie_face.png");
	sf::Sprite sprite(texture);

	sf::RectangleShape boite(sf::Vector2f(60, 40));
	boite.setPosition(window.getSize().x - 60, window.getSize().y - 65);
	boite.setFillColor(sf::Color(0, 0, 0));
	window.draw(boite);

	sprite.setPosition(window.getSize().x - 45, window.getSize().y - 62);
	window.setView(fixed);
	window.draw(sprite);

	sf::Text texteVie;
	sf::Font font;
	if (!font.loadFromFile("./assets/arial.ttf")) { std::cout << "Erreur de chargement de la police arial.ttf" << std::endl; }
	texteVie.setFont(font);
	texteVie.setCharacterSize(12);
	texteVie.setColor(sf::Color::White);

	texteVie.setString(zomb.getNom());
	texteVie.setPosition(window.getSize().x - 48, window.getSize().y - 15);
	window.draw(texteVie);
	sf::RectangleShape vie(sf::Vector2f(zomb.getVie(), 3));
	vie.setPosition(window.getSize().x - 42, window.getSize().y - 25);
	vie.setFillColor(sf::Color(255, 255, 0));
	window.draw(vie);
}

	void static afficherMenuPause(sf::RenderWindow& window, Joueur j) {
		sf::RectangleShape boite(sf::Vector2f(window.getSize().x/2, window.getSize().y / 2));
		boite.setFillColor(sf::Color(150, 50, 250));

		// définit un contour orange de 10 pixels d'épaisseur
		boite.setOutlineThickness(10);
		boite.setOutlineColor(sf::Color(250, 150, 100));
		boite.setPosition(50, 1);
		window.draw(boite);
	}
	
};