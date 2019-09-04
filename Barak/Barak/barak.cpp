#include "barak.h"

Unit::Unit(int hp, int dmg, string name):hp(hp),dmg(dmg), name(name)
{

}

Unit::~Unit()
{
}

int Unit::getHP() const
{
	return hp;
}

void Unit::setHP(int hp)
{
	this->hp = hp;
}

int Unit::getDmg() const
{
	return dmg;
}

string Unit::getName() const
{
	return name;
}

CrazyScientist::CrazyScientist(int hp, int dmg, string name):Unit(hp,dmg,name)
{
}

void CrazyScientist::Attack(Unit * u)
{
	u->setHP(u->getHP() - getDmg());

}

void CrazyScientist::Info()
{
	cout << getName() << " have " << getHP() << " hp and " << getDmg() << " damage" << endl;

}

SeeSoldat::SeeSoldat(int hp, int dmg, string name):Unit(hp, dmg, name)
{
	
}

void SeeSoldat::Attack(Unit * u)
{
	u->setHP(u->getHP() - getDmg());
}

void SeeSoldat::Info()
{
	cout << getName() << " have " << getHP() << " hp and " << getDmg() << " damage" << endl;
}

Doctor::Doctor(int hp, int dmg, string name):Unit(hp, dmg, name)
{
}

void Doctor::Attack(Unit * u)
{
	u->setHP(u->getHP() + getDmg());
}

void Doctor::Info()
{	cout << getName() << " have " << getHP() << " hp and " << getDmg() << " damage" << endl;
}

Unit * MIllitaryBarack::createPlayer( int numb)
{
	switch (numb) {
	case 1:return new CrazyScientist();
	case 2:return new SeeSoldat();
	case 3: return new Doctor();
	}
	
}

Barack::~Barack()
{
}
Weapon::~Weapon()
{
}

void Gun::ShotorHit()
{
	cout << "You have a gun\n";
}

Weapon * Gun::clone()
{
	return new Gun(*this);
}

void Mashingun::ShotorHit()
{
	cout << "You have Mashingun\n";
}

Weapon * Mashingun::clone()
{
	return new Mashingun(*this);
}

void Blade::ShotorHit()
{
	cout << "You have a blade\n";

}

Weapon * Blade::clone()
{
	return new Blade(*this);
}

Weapon * Prototyp::createWP(int numb)
{
	switch (numb) {
	case 1:
	case 2:
	case 3:
		return prototyp[numb - 1]->clone();
		break;
	default:
		return prototyp[0]->clone();
	}
}

void Play(vector<Unit*>  first, vector<Unit *>second, vector<Weapon*>forpl1, vector<Weapon*>forpl2)
{
	int numb;
	int counter = 0;
	int count = 0;
	while (counter != 3) {
		cout << "First Player bild a team\n";
		cout << "Choise a warior\n";
		cout << "1. CrazyScientist\n";
		cout << "2. SeeSoldat\n";
		cout << "3. Doctor\n";
		cin >> numb;
		first.push_back(MIllitaryBarack::createPlayer(numb));
		cout << "First Player choise a weapon\n";
		cout << "1. Gun\n";
		cout << "2. Mashingun\n";
		cout << "3. Blade\n";
		cout << "0. Logout\n";
		cin >> numb;
		forpl1.push_back(Prototyp::createWP(numb));
		counter++;
	}
	cout << "First Player: \n";
	for (auto elem : first) {
		elem->Info();
		cout << endl;
	}

	cout << "Weapon of First Player:\n";
	for (auto elem : forpl1) {
		elem->ShotorHit();
		cout << endl;
	}
	while (count != 3) {
		cout << "Second Player bild a team\n";
		cout << "Choise a warior\n";
		cout << "1. CrazyScientist\n";
		cout << "2. SeeSoldat\n";
		cout << "3. Doctor\n";
		cout << "0. Logout\n";
		cin >> numb;

		second.push_back(MIllitaryBarack::createPlayer(numb));
		cout << "First Player choise a weapon\n";
		cout << "1. Gun\n";
		cout << "2. Mashingun\n";
		cout << "3. Blade\n";
		cout << "0. Logout\n";
		cin >> numb;
		forpl2.push_back(Prototyp::createWP(numb));
		count++;
	}
	cout << "Second Player: \n";
	for (auto elem : second) {
		elem->Info();
		cout << endl;
	}

	cout << "Weapon of Second Player:\n";
	for (auto elem : forpl2) {
		elem->ShotorHit();
		cout << endl;
	}
	int number=100;
	while (number != 0) {
		cout << "First Player atacked\n";
		for (int i = 0; i < 3; i++) {
			if (second[i]->getHP() > 0) {
				first[i]->Attack(second[i]);
				second[i]->Info();
				cout << endl;
			}
		else  {
				break;
		}
			
		}
		cout << "Second Player atacked\n";
		for (int i = 0; i < 3; i++) {
			if (first[i]->getHP() > 0){
			second[i]->Attack(first[i]);
			first[i]->Info();
			cout << endl;
		}
		else {
		break;
		}
		}
		for (auto el : first) {
			if (el->getHP() <= 0) {
				return;
			}
		}
		for (auto el : first) {
			if (el->getHP() <= 0) {
				return;
			}
		}
	}
}

