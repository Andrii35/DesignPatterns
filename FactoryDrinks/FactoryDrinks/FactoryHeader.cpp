#include "FactoryHeader.h"

Drink::Drink(string name):name(name)
{
}

void Drink::Print()
{
	cout << name << endl;
}

Botl::Botl(string name):Drink(name)
{
}

Product::Product(string name):Drink(name)
{
}

PepsBotl::PepsBotl(string name):Botl(name)
{
}

Pepsidrink::Pepsidrink(string name):Product(name)
{
}

Cocabotle::Cocabotle(string name):Botl(name)
{
}

Cocadrink::Cocadrink(string name):Product(name)
{
}
ColaFactory::ColaFactory() {

}

ColaFactory * ColaFactory::getCocacola()
{
	if (cocacola == nullptr)
		cocacola = new ColaFactory();
	return cocacola;
}

Botl * ColaFactory::createBotl()
{
	return new Cocabotle();
}

Product * ColaFactory::createDrink()
{
	return new Cocadrink();
}

PepsiFactory::PepsiFactory() {

}

PepsiFactory * PepsiFactory::getDrink()
{
	if (drink == nullptr) {
		drink = new PepsiFactory();
	}
	return drink;
}

Botl * PepsiFactory::createBotl()
{
	return new PepsBotl();
}

Product * PepsiFactory::createDrink()
{
	return new Pepsidrink();
}


Client::Client(string name):name(name)
{
}

void Client::Factory(ColaFactory * coca, PepsiFactory * pepsi)
{
	
		int choise = 100;
		while (choise != 0) {
			cout << "Choise an action\n";
			cout << "1. Cola\n";
			cout << "2. Pepsi\n";
			cout << "0. Exit\n";
			cin >> choise;
			switch (choise) {
			case 1: {
				Botl*one= coca->createBotl();
				Product*two=coca->createDrink();
				one->Print();
				two->Print();
				break;
			}
			case 2: {
				Botl*one = pepsi->createBotl();
				Product*two = pepsi->createDrink();
				one->Print();
				two->Print();
				break;
			}
			}
		}
}

//Pepsi * BotleFactory::createPepsi()
//{
//
//	return new Pepsibotle();
//}
//
//Cocacola * BotleFactory::createCoca()
//{
//	return new Cocabotle();
//}
//
//Pepsi * DFactory::createPepsi()
//{
//	return new Pepsidrink();
//}
//
//Cocacola * DFactory::createCoca()
//{
//	return new Cocadrink();
//}
