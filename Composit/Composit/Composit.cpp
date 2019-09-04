#include "Composit.h"

Component::Component(string name, int size):name(name), size(size)
{
}

string Component::getName() const
{
	return name;
}


Component::~Component()
{
}

Composite::Composite(string name):Component(name)
{
}

Composite::~Composite()
{
}

void Composite::Add(Component * c)
{
	tree.push_back(c);
}

void Composite::Remove(int index)
{
	tree.erase(tree.begin() + index);
}

Component * Composite::getChild(int index)
{
	if (index < tree.size() && index >= 0)
		return tree[index];
	throw("Invalid index\n");
}

void Composite::Operation()
{
	cout << getName() << endl;
	for (auto el : tree) {
		{
			el->Operation();
			cout << endl;
		}
	}
	cout << getName()<<" size:" << getSize();
	cout << endl;
}

int Composite::getSize()
{
	int temp = 0;
	for (auto el : tree) {
		temp += el->getSize();
	}
	
	return temp ;
}


Unit::Unit(string name, int size):Component(name, size)
{
}

void Unit::Add(Component * c)
{
	throw("Invalid index\n");
}

void Unit::Remove(int index)
{
	throw("Invalid index\n");
}

Component * Unit::getChild(int index)
{
	throw("Invalid index\n");
}

void Unit::Operation()
{
	cout << getName() << " size: ";
	cout << getSize() << "\t";
}

int Unit::getSize()
{
	return size;
}
