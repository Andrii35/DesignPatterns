#pragma once
#include<iostream>
#include<string>
using namespace std;

// Porodjujuchij patern  //Singleton
class Singleton {
	int value;
	static Singleton*obj;
	Singleton(int v = 4100);
public:
	static Singleton*getObj(int v = 4100);
	void setValue(int money);
	int getValue()const;

};

class Logger {
	string user;
	static Logger*use;
	Logger(string u = "user");
public:
	static Logger*getUse(string u="user");
	string getUser()const;
	void setUser(string u);
	void Print();
};

// Abstract Factory

