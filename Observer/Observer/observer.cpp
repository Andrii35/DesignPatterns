#include "observer.h"

Product::Product(string name, double price):name(name),price(price)
{
}

Product::~Product()
{
}

void Product::Atach(Bayer * b)
{
	buyers.push_back(b);
}

void Product::Detach(Bayer * b)
{
	int index = 0;
	for (auto el : buyers) {
		
		if (el == b) {
			buyers.erase(buyers.begin() + index);
		}
		index++;
	}

}

double Product::getPrice() const
{
	return price;
}

string Product::getName() const
{
	return name;
}

void Product::Notify()
{
	for (auto el : buyers) {
		el->Update(this);
	}
}

void Product::setPrice(double price)
{
	if (price != this->price) {
		Notify();
	}
}

Car::Car(string name, double price):Product(name,price)
{
}

UkranianBuyer::UkranianBuyer(string name, Product*pr):name(name), pr(pr)
{
}

Product * UkranianBuyer::getProduct()
{
	return pr;
}

void UkranianBuyer::setProduct(Product * pr)
{
	this->pr = pr;
}

void UkranianBuyer::Update(Product * pr)
{
	cout << pr->getName() << " price was chainged\n";
	
}


