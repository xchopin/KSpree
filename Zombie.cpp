#include "Zombie.h"
#include "Personnage.cpp"


using namespace std;

class Zombie {

private:

	
	int vie;
	int degat;
	int vitesse;
	int x;
	int y;

public:

	// - - - Constructeur - - -

	Zombie(int v, int d) {

		this->vie = v;
		this->degat = d;
		this->vitesse = 2;
		this->x = 0;
		this->y = 0;
	};

	Zombie::~Zombie()
	{
	
	}


	// - - - Getter - - -

	int getVie() { return vie; }
	int getDegat() { return degat; }
	int getVitesse() { return vitesse; }
	int getX() { return x; }
	int getY() { return y; }
	

	// - - - Setter - - -

	void setVie(int v) { this->vie = v; }
	void setDegat(int d) { this->degat = d; }
	void setVitesse(int v) { this->vitesse = v; } 

	void setX(int x2) { this->x = x2; }
	void setY(int a) { this->y = a; }

	// - - - Méthodes de jeu - - -

	void perdreVie(int x) {
		if (this->getVie() - x > 0) {
			this->setVie(this->vie - x);
		}
		else {
			this->setVie(0);
		}
	}

	void attaquer(Personnage p) {
		p.perdreVie(this->getDegat());
	}





};
