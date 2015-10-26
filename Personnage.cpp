#include "Personnage.h";

	Personnage::Personnage(string n, int life, int v, int d){
		m_nom = n;
		m_vie = life;
		m_degat = d;
		m_vitesse = v;
		m_x = 0;
		m_y = 0;
	}


	void Personnage::chargerTexture(string fichier) {
		if (!m_texture.loadFromFile(fichier)) { cout << "Erreur lors du chargement de " << fichier << " !" << endl; }

		m_animationMarcherBas.setSpriteSheet(m_texture);
		m_animationMarcherBas.addFrame(sf::IntRect(32, 0, 32, 32));
		m_animationMarcherBas.addFrame(sf::IntRect(64, 0, 32, 32));
		m_animationMarcherBas.addFrame(sf::IntRect(32, 0, 32, 32));
		m_animationMarcherBas.addFrame(sf::IntRect(0, 0, 32, 32));

		m_animationMarcherGauche.setSpriteSheet(m_texture);
		m_animationMarcherGauche.addFrame(sf::IntRect(32, 32, 32, 32));
		m_animationMarcherGauche.addFrame(sf::IntRect(64, 32, 32, 32));
		m_animationMarcherGauche.addFrame(sf::IntRect(32, 32, 32, 32));
		m_animationMarcherGauche.addFrame(sf::IntRect(0, 32, 32, 32));

		m_animationMarcherRight.setSpriteSheet(m_texture);
		m_animationMarcherRight.addFrame(sf::IntRect(32, 64, 32, 32));
		m_animationMarcherRight.addFrame(sf::IntRect(64, 64, 32, 32));
		m_animationMarcherRight.addFrame(sf::IntRect(32, 64, 32, 32));
		m_animationMarcherRight.addFrame(sf::IntRect(0, 64, 32, 32));

		m_animationMarcherUp.setSpriteSheet(m_texture);
		m_animationMarcherUp.addFrame(sf::IntRect(32, 96, 32, 32));
		m_animationMarcherUp.addFrame(sf::IntRect(64, 96, 32, 32));
		m_animationMarcherUp.addFrame(sf::IntRect(32, 96, 32, 32));
		m_animationMarcherUp.addFrame(sf::IntRect(0, 96, 32, 32));

		m_animatedSprite = AnimatedSprite(sf::seconds(0.2), true, false); //This creates a new AnimatedSprite and replaces the old one with the same variable
		m_animatedSprite.setPosition(sf::Vector2f(400, 100)); //this can now safely be set
	}


	//Méthode pour animer 
	void Personnage::jouerAnimation() {
		m_animatedSprite.play(*m_animationActuel);
		m_animatedSprite.setPosition(Personnage::getX(), Personnage::getY());
	}

	void Personnage::updateAnimation(sf::Time frameTime) {
		m_animatedSprite.update(frameTime);
	}
	
	void Personnage::attaquer(Personnage p) {
		p.perdreVie( Personnage::getDegat() );
	}

	void Personnage::perdreVie(int x) {
		if (m_vie - x > 0) {   m_vie = (m_vie - x); }   else   {  m_vie = 0;  }
	}


	// - - - Getter - - -

	int Personnage::getVie() { return m_vie; }
	int Personnage::getDegat() { return m_degat; }
	int Personnage::getVitesse() { return m_vitesse; }
	int Personnage::getX() { return m_x; }
	int Personnage::getY() { return m_y; }
	string Personnage::getNom() { return m_nom; }

	Animation Personnage::getAnimationMarcherBas(){ return m_animationMarcherBas; }
	Animation Personnage::getAnimationMarcherGauche(){ return m_animationMarcherGauche; }
	Animation Personnage::getAnimationMarcherRight() { return m_animationMarcherRight;  }
	Animation Personnage::getAnimationMarcherUp() { return m_animationMarcherUp; }
	Animation* Personnage::getAnimationActuel() { return m_animationActuel; }
	AnimatedSprite Personnage::getAnimatedSprite() { return m_animatedSprite; }


	// - - - Setter - - -

	void Personnage::setVie(int v) { m_vie = v; }
	void Personnage::setDegat(int d) { m_degat = d; }
	void Personnage::setVitesse(int v) { m_vitesse = v; }
	void Personnage::setNom(string n) { m_nom = n; }
	void Personnage::setX(int x2) { m_x = x2; }
	void Personnage::setY(int a) { m_y = a; }


