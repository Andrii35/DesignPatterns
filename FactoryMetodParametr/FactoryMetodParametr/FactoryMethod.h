#pragma once
#include<iostream>
#include<string>
#include<vector>

enum TYPE { ARCHER = 1, MAGE, SWORDSMAN };

using namespace std;


class Unit abstract {
public:
	virtual~Unit();
	virtual void Play() = 0;
};

class Archer : public Unit {
public:
	void Play();
};

class Mage :public Unit {
public:
	void Play();
};
class Swordsman :public Unit {
public:
	void Play();
};

class FactoryMethod abstract {

public:

	static Unit *createPlayer(TYPE temp);
};