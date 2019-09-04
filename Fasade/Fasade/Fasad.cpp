#include "Fasad.h"

Computer::Computer()
{
}

Computer::~Computer()
{
}

void Computer::ShowScreen()
{
	cout << "Screen\n";
}

void Computer::sentSound()
{
	cout << "Sound\n";
}

void Computer::closeAll()
{
	cout << "All close\n";
}

void Computer::showDesctop()
{
	cout << "Desctop\n";
}

void Computer::isReady()
{
	cout << "Computer is ready\n";
}

Facade::Facade(Computer * c):c(c)
{
}

Facade::~Facade()
{
	delete c;
}

void Facade::turnOn()
{
	c->ShowScreen();
	c->showDesctop();
	c->sentSound();
	c->isReady();
}

void Facade::turnOff()
{
	c->closeAll();
}
