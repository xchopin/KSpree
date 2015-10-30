#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "AnimatedSprite.hpp"
#include <vector>
#include <iostream>
#include "Animation.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
class Personnage {

private:

	std::string m_nom;
	
	int m_degat;
	int m_vitesse;
	int m_x;
	int m_y;
	int m_vie;


public:
	
	Animation m_animationMarcherBas;
	Animation m_animationMarcherGauche;
	Animation m_animationMarcherRight;
	Animation m_animationMarcherUp;
	Animation* m_animationActuel = &m_animationMarcherBas;
	sf::Texture m_texture;
	AnimatedSprite m_animatedSprite;

	Personnage(string n, int life, int v, int d);
	void chargerTexture(string fichier);
	void jouerAnimation();
	void updateAnimation(sf::Time frameTime);
	void perdreVie(int x);
	void attaquer(Personnage p);
	void seFaireAttaquer(Personnage p); //Méthode alternative car putain de problème de pointeur ,long à expliquer ici...
	bool isDead();

	// - - - Getter - - -

	int getVie();
	int getDegat();
	int getVitesse();
	int getX();
	int getY();
	string getNom();
	Animation getAnimationMarcherBas();
	Animation getAnimationMarcherGauche();
	Animation getAnimationMarcherRight();
	Animation getAnimationMarcherUp();
	Animation* getAnimationActuel();
	AnimatedSprite getAnimatedSprite();


	// - - - Setter - - -

	void setVie(int v);
	void setDegat(int d);
	void setVitesse(int v);
	void setNom(string n);
	void setX(int x2);
	void setY(int a);

};

#endif