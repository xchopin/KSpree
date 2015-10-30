#include "Zombie.h"



Zombie::Zombie(): Personnage("Zombie", 20, 1, 10) {
	//Zombie::m_animActu;
//	m_animActu.setSpriteSheet(m_texture);
	Zombie::chargerTexture("./assets/zombie.png");
	

}


Zombie::~Zombie()
{
}

void Zombie::jouerAnimation() {
	m_animatedSprite.play(m_animActu);
	m_animatedSprite.setPosition(Zombie::getX(), Zombie::getY());

}

void Zombie::chargerTexture(string fichier) {
	if (!m_texture.loadFromFile(fichier)) { cout << "Erreur lors du chargement de " << fichier << " !" << endl; }
	m_texture.setSmooth(true);
	m_animActu.setSpriteSheet(m_texture);
	m_animActu.addFrame(sf::IntRect(32, 0, 32, 32));
	m_animActu.addFrame(sf::IntRect(64, 0, 32, 32));
	m_animActu.addFrame(sf::IntRect(32, 0, 32, 32));
	m_animActu.addFrame(sf::IntRect(0, 0, 32, 32));


	m_animatedSprite = AnimatedSprite(sf::seconds(0.2), true, false); //This creates a new AnimatedSprite and replaces the old one with the same variable
	m_animatedSprite.setPosition(sf::Vector2f(400, 100)); //this can now safely be set
}

// return un boolean pour savoir si on doit play ou stop  ;)
bool Zombie::poursuivre(Joueur j) {
	bool res = true;
	  // X 
	
	if (j.getX()+24< Zombie::getX()) {
		Zombie::setX(Zombie::getX() - Zombie::getVitesse() );
	
		m_animActu.effacerFrame();
		m_animActu.addFrame(sf::IntRect(32, 32, 32, 32));
		m_animActu.addFrame(sf::IntRect(64, 32, 32, 32));
		m_animActu.addFrame(sf::IntRect(32, 32, 32, 32));
		m_animActu.addFrame(sf::IntRect(0, 32, 32, 32));

	} else if (j.getX()-24 > Zombie::getX() ) {
		Zombie::setX(Zombie::getX() + Zombie::getVitesse() );

		m_animActu.effacerFrame();
		m_animActu.addFrame(sf::IntRect(32, 64, 32, 32));
		m_animActu.addFrame(sf::IntRect(64, 64, 32, 32));
		m_animActu.addFrame(sf::IntRect(32, 64, 32, 32));
		m_animActu.addFrame(sf::IntRect(0, 64, 32, 32));
	}

	// Y
	else if (j.getY()+24< Zombie::getY()) {
		Zombie::setY(Zombie::getY() - Zombie::getVitesse());
	
	}

	else if (j.getY()-24 >  Zombie::getY()) {
		Zombie::setY(Zombie::getY() + Zombie::getVitesse());
		m_animActu.effacerFrame();
		m_animActu.addFrame(sf::IntRect(32, 0, 32, 32));
		m_animActu.addFrame(sf::IntRect(64, 0, 32, 32));
		m_animActu.addFrame(sf::IntRect(32, 0, 32, 32));
		m_animActu.addFrame(sf::IntRect(0, 0, 32, 32));
	} else {

		res = false; // il ne poursuit pas le joueur ;)
	}

	return res;
}