#pragma once
#include<iostream>
#include<string>
#include<vector>

enum TYPE { ARCHER = 1, MAGE, SWORDSMAN };

using namespace std;


class Unit abstract {
public:
	virtual~Unit() {}
	virtual void Play() = 0;
	virtual Unit*clone() = 0;
};

class Archer : public Unit {
public:
	void Play();
	Unit*clone();
};

class Mage :public Unit {
public:
	void Play();
	Unit*clone();
};
class Swordsman :public Unit {
public:
	void Play();
	Unit*clone();
};

class createPrototype {

	static Unit*prototypes[3];
public:
	static Unit *createPl(TYPE temp);

};

