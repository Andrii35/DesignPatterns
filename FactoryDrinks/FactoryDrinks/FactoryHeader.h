#pragma once
#include<iostream>
#include<string>

using namespace std;

class Drink {
	string name;
public:
	Drink(string name = "production");
	void Print();

};

class Botl:public Drink {
public:
	Botl(string name = "botl");
};
class Product :public Drink {
public:
	Product(string name = "drink");
};
class PepsBotl :public Botl {
public:
	PepsBotl(string name = "Pepsi botle");
};
class Pepsidrink : public Product {
public:
	Pepsidrink(string name = "Pepsi");
};

class Cocabotle:public Botl{
public:
	Cocabotle(string name = "Coca-cola botle");
};
class Cocadrink :public Product {
public:
	Cocadrink(string name = "Coca-cola drink");
};

__interface DrinkFactory {
public:
	virtual Botl*createBotl() = 0;
	virtual Product*createDrink() = 0;
};

//class BotleFactory :public DrinkFactory {
//public:
//	Pepsi*createBotles();
//	Cocacola*createCoca();
//};
//
//class DFactory :public DrinkFactory {
//public:
//	Pepsi*createBotles();
//	Cocacola*createCoca();
//};
class ColaFactory :public DrinkFactory {
	static ColaFactory*cocacola;
	ColaFactory();
public:
	static ColaFactory*getCocacola();
	Botl*createBotl();
	Product*createDrink();
};

class PepsiFactory :public DrinkFactory {
	static PepsiFactory *drink;
	PepsiFactory();
public:
	static PepsiFactory*getDrink();
	Botl*createBotl();
	Product*createDrink();

};

class Client{
	string name;
public:
	Client(string name = "Client");
	void Factory(ColaFactory * botl, PepsiFactory * drink);
};