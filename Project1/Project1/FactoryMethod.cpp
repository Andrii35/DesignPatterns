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

FactoryMethod::~FactoryMethod()
{
}

Unit * FactoryMethodArcher::createPlayer()
{
	return new Archer;
}

Unit * FactoryMethodMage::createPlayer()
{
	return new Mage;
}

Unit * FactoryMethodSwordsman::createPlayer()
{
	return new Swordsman;
}
