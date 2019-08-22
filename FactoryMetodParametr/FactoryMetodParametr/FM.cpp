#include "FactoryMethod.h"

void Archer::Play()
{
	cout << "Play Archer\n";
}

void Mage::Play()
{
	cout << "Play Mage\n";
}

void Swordsman::Play()
{
	cout << "Play Swordsman\n";
}

Unit::~Unit()
{
}

Unit * FactoryMethod::createPlayer(TYPE temp)
{
	switch (temp) {
	case ARCHER:return new Archer();
	case MAGE:return new Mage();
	case SWORDSMAN: return new Swordsman();
	}

}
