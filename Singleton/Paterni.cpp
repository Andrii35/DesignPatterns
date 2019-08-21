#include "Paterni.h"

Singleton * Singleton::getObj(int v)
{
	if (obj == nullptr)
		obj = new Singleton(v);
	return obj;

}
Singleton::Singleton(int v) :value(v) {

}

void Singleton::setValue(int money)
{
	value = money;
}

int Singleton::getValue() const
{
	return value;
}

Logger::Logger(string u):user(u)
{

}

Logger * Logger::getUse(string u)
{
	if (use == nullptr)
		use = new Logger(u);
	return use;
}

string Logger::getUser() const
{
	return user;
}

void Logger::setUser(string u)
{
	user = u;
}

void Logger::Print()
{
	cout << user << endl;
}
