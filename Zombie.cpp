#include "Zombie.h"



Zombie::Zombie(): Personnage("Zombie", 20, 1, 10) {
	Zombie::chargerTexture("./assets/zombie.png");
}


Zombie::~Zombie()
{
}
