
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Gameplay {
public:




	static void Gameplay::creerCurseur(sf::RenderWindow& window, int largeurCurseur) {
		window.setMouseCursorVisible(false);
		sf::View fixed = window.getView();
		sf::Texture texture;
		texture.loadFromFile("./assets/crosshair.png");
		sf::Sprite sprite(texture);
		sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.setView(fixed);
		window.draw(sprite);
	}

	void Gameplay::isOnEnnemie( sf::RenderWindow& window) {
		sf::Vector2i curseur = sf::Mouse::getPosition(window);
		
		/**for (int i = 0; i < tab.size(); i++) {
			if (tab[i].getX() >= curseur.x - 10 && tab[i].getX() <= curseur.x + 10) {
				cout << "LEL" << endl;
			}

		}*/
	}


};





