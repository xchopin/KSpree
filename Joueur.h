#ifndef DEF_JOUEUR
#define DEF_JOUEUR
#include <iostream>
#include <string>
#include "Personnage.h"


class Joueur : public Personnage {
public:
	bool m_isKeyboardUsed;

	// Méthodes
	Joueur(string n, int life, int v, int d); // Constructeur
	void jouerAnimation(); // animer le joueur , méthode légérement différente pour prendre en compte le clavier ;)
	void clavier(); // Méthode pour déplacer le perso
	void dessinerHUD(sf::RenderWindow& window, sf::Clock& temps); // pas vraiment le bonne endroit mais #YOLO

};

#endif
