#include <iostream>
#include <string>
#include "Joueur.h"

void dessinerHUD(Joueur j, sf::RenderWindow& window, sf::Clock& temps) {

	// Boite
	sf::RectangleShape boite(sf::Vector2f(window.getSize().x, 30));
	boite.setPosition(0, window.getSize().y - 30);
	boite.setFillColor(sf::Color(0, 0, 0));
	window.draw(boite);

	// Texte
	sf::Text texteVie;
	sf::Font font;
	if (!font.loadFromFile("./assets/arial.ttf")) { std::cout << "Erreur de chargement de la police arial.ttf" << std::endl; }
	texteVie.setFont(font);
	texteVie.setCharacterSize(15);
	texteVie.setColor(sf::Color::White);
	texteVie.setStyle(sf::Text::Bold);
	texteVie.setString("VIE: ");
	texteVie.setPosition(1, window.getSize().y - 30);
	window.draw(texteVie);

	// La vie
	sf::RectangleShape vie(sf::Vector2f(/**Joueur::getVie() **/ 2, 8));
	vie.setPosition(1, window.getSize().y - 10);
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