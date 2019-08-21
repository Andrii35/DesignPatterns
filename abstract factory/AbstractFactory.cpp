#include "AbstractFactory.h"

Toy::Toy(string name):name(name)
{
}

void Toy::Print()
{
	cout << name << endl;
}

Bear::Bear(string n):Toy(n)
{
}

Cat::Cat(string n):Toy(n)
{
}

TeddyCat::TeddyCat():Cat("teddy cat")
{
}

WoodenCat::WoodenCat():Cat("wooden cat")
{

}

TeddyBear::TeddyBear():Bear("teddy bear")
{
}

WoodenBear::WoodenBear():Bear("wooden bear")
{
}

Bear * WoodenToys::createBear()
{
	return new WoodenBear();
}

Cat * WoodenToys::creatCat()
{
	return new WoodenCat();
}

Bear * TeddyToys::createBear()
{
	return new TeddyBear();
}

Cat * TeddyToys::creatCat()
{
	return new TeddyCat();
}

void UseToys(ToysFactory * obj)
{
	/*int numb = 100;
	while (numb != 0) {
		cout << "Choise an action/n";
		cout << "1. Create wooden bear/n";
		cout << "2. Create taddy bear/n";
		cout << "3. Create wooden cat/n";
		cout << "4. Create taddy cat/n";
		cout << "0. Create wooden bear/n";
	}*/
	Bear*bear = obj->createBear();
	Cat*cat = obj->creatCat();
	bear->Print();
	cat->Print();

}
