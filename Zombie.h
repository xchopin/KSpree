#ifndef DEF_ZOMBIE
#define DEF_ZOMBIE
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Joueur.h"

class Zombie : public Personnage {
public:
	Zombie();
	~Zombie();

	bool poursuivre(Joueur j);
	void jouerAnimation();
	void chargerTexture(string fichier);
	Animation m_animActu ;

};

#endif