#include"Prototyp.h"
void Archer::Play()
{
	cout << "Play Archer\n";
}

Unit * Archer::clone()
{
	return new Archer(*this);
}

void Mage::Play()
{
	cout << "Play Mage\n";
}

Unit * Mage::clone()
{
	return new Mage(*this);
}

void Swordsman::Play()
{
	cout << "Play Swordsman\n";
}

Unit * Swordsman::clone()
{
	return new Swordsman(*this);
}


Unit * createPrototype::createPl(TYPE temp)
{
	switch (temp) {
	case ARCHER:
	case MAGE:
	case SWORDSMAN:
		return prototypes[temp - 1]->clone();
		break;
	default:
		return prototypes[0]->clone();
	}
}