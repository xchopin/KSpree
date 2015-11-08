#include "Launcher.h"


class Launcher {
public:
	static int afficherLauncher(sf::RenderWindow& window) {
		sf::sleep(sf::milliseconds(80));
		sf::Texture fond_bg;
		fond_bg.loadFromFile("./assets/background.png");
		sf::Sprite bg;
		bg.setTexture(fond_bg);
		window.draw(bg);

		if (selectionnerChoix(window, 630, 246, 775, 286)) {
			fond_bg.loadFromFile("./assets/background1.png");
			bg.setTexture(fond_bg);
			window.draw(bg);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				return 1;
			}

		} else if (selectionnerChoix(window, 687, 345, 775, 385)) {
			fond_bg.loadFromFile("./assets/background2.png");
			bg.setTexture(fond_bg);
			window.draw(bg);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				window.close();
				return 0; // obligé de mettre un return ^^
			}

		} else {
			return 0;
		}


	}

	static bool selectionnerChoix(sf::RenderWindow& window, int x, int y, int x2, int y2) {
		sf::Vector2i curseur = sf::Mouse::getPosition(window);

		bool res = false;
		if ((x <= curseur.x) && (curseur.x <= x2) && (y <= curseur.y) && (curseur.y <= y2)) {
			res = true;
		}

		return res;
	}


};
