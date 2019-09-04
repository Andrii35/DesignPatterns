#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Unit abstract {
	string name;
	int hp;
	int dmg;
public:
	Unit(int hp=0, int dmg=0, string name="none");
	virtual~Unit();
	int getHP()const;
	void setHP(int hp);
	int getDmg()const;
	string getName()const;
	virtual void Attack(Unit*u) = 0;
	virtual void Info() = 0;
};

class CrazyScientist : public Unit {
public:
	CrazyScientist(int hp = 75, int dmg = 20, string name="Scientist");
	void Attack(Unit*u);
	void Info();
};
class SeeSoldat :public Unit {
public:
	SeeSoldat(int hp = 100, int dmg = 15, string name="Soldat");
	void Attack(Unit*u);
	void Info();
};
class Doctor :public Unit {

public:
	Doctor(int hp = 50, int dmg = 10, string name="Doctor");
	void Attack(Unit*u);
	void Info();
};
class Weapon abstract {
public:
	virtual~Weapon();
	virtual void ShotorHit() = 0;
	virtual Weapon* clone() = 0;
};
class Gun :public Weapon {
	void ShotorHit();
	Weapon* clone();
};

class Mashingun :public Weapon {
	void ShotorHit();
	Weapon*clone();
};

class Blade :public Weapon {
	void ShotorHit();
	Weapon*clone();
};

class Prototyp {
protected:
	static Weapon*prototyp[3];
public:
	static Weapon*createWP(int numb);
};
class Barack abstract {
public:
	virtual~Barack();
	virtual Unit*createPlayer() = 0;
};

class MIllitaryBarack :public Barack {
public:
	static Unit*createPlayer( int numb);

};

void Play(vector<Unit*>first, vector<Unit*>second, vector<Weapon*>forpl1, vector<Weapon*>forpl2);