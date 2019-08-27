#include "mashine.h"

oldCoffeMashine::oldCoffeMashine(int coffe, int milk, int globalprice):coffe(coffe),milk(milk),globalprice(globalprice)
{
}

int oldCoffeMashine::getCoffe() const
{
	return coffe;
}

void oldCoffeMashine::setCoffe(int coffe)
{
	this->coffe = coffe;
}

int oldCoffeMashine::getMilk() const
{
	return milk;
}

void oldCoffeMashine::setMilk(int milk)
{
	this->milk = milk;
}

int oldCoffeMashine::getGlobalPrice() const
{
	return globalprice;
}

void oldCoffeMashine::setGlobalPrice(int globalprice)
{
	this->globalprice = globalprice;
}

void oldCoffeMashine::makeCoffe()
{
	if (isReade()) {
		cout << "Cofe\n";
		globalprice +=10;
		cout << "Price: " << getGlobalPrice();
		cout << endl;
		setCoffe(getCoffe() - 1);
		
	}
	else {
		cout << "Coffemashine has'nt ingridients\n";
	}
}

void oldCoffeMashine::addMilk()
{
	if (isReade()) {
		cout << "Coffe with milk\n";
		globalprice +=2;
		cout << "Price - " << globalprice << endl;
		cout << endl;
		setMilk(getMilk() - 1);
		
	}
	else {
		cout << "Coffemashine has'nt ingridients\n";
	}
}

bool oldCoffeMashine::isReade()
{
	if (coffe > 1 && milk > 1)
		return true;
}

AdapterCoffe::AdapterCoffe(int coffe, int milk, int globalprice):oldCoffeMashine(coffe,milk,globalprice)
{
}

void AdapterCoffe::makePureCoffe()
{
	oldCoffeMashine::makeCoffe();
}

void AdapterCoffe::CoffewithMilk()
{
	oldCoffeMashine::makeCoffe();
	oldCoffeMashine::addMilk();
}

void NewMenu()
{
	int choise = 100;
	while (choise != 0) {
		cout << "Choise a drink\n";
		cout << "1. Pure coffe - 10 grn\n";
		cout << "2. Coffe with milk - 12 grn\n";
		cout << "0. Exit\n";
		cin >> choise;
		switch (choise) {
		case 1: {
			
			NewCoffeMashine* mashine=new AdapterCoffe();
			mashine->makePureCoffe();
			break;
		}
		case 2: {
			NewCoffeMashine* mashine = new AdapterCoffe();
			mashine->CoffewithMilk();
			break;
		}
		}
		
	}
}

void oldMenu()
{
	int choise = 100;
	while (choise != 0) {
		cout << "Choise a drink\n";
		cout << "1. Coffe - 10 grn\n";
		cout << "2.Add milk - 12 grn\n";
		cout << "0. Exit\n";
		cin >> choise;
		switch (choise) {
		case 1: {
			oldCoffeMashine mashine;
			mashine.makeCoffe();
			break;
		}
		case 2: {
			oldCoffeMashine mashine;
			mashine.makeCoffe();
			mashine.addMilk();
			break;
		}
		}

	}
}

