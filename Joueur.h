#ifndef DEF_JOUEUR
#define DEF_JOUEUR
#include <iostream>
#include <string>
#include "Personnage.h"


class Joueur : public Personnage {
public:
	bool m_isKeyboardUsed;
	int m_kill;
	int m_munition;
	// M�thodes
	Joueur(string n, int life, int v, int d); // Constructeur
	int getMunition();
	void setMunition(int x);
	void rechargerMunition();
	void jouerAnimation(); // animer le joueur , m�thode l�g�rement diff�rente pour prendre en compte le clavier ;)
	void clavier(); // M�thode pour d�placer le perso
	

};

#endif
