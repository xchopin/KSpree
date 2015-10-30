#include <iostream>
#include <string>
#include "Joueur.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>
class HUD{
public:
void static HUD::afficherInfoZombie(sf::RenderWindow& window,Zombie zomb) {
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

};