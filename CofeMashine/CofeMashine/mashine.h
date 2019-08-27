#pragma once
#include<iostream>
#include<string>

using namespace std;

class oldCoffeMashine {
	int coffe;
	int milk;
	int globalprice;
public:
	oldCoffeMashine(int coffe = 100, int milk = 100, int globalprice = 0);
	int getCoffe()const;
	void setCoffe(int coffe);
	int getMilk()const;
	void setMilk(int milk);
	int getGlobalPrice()const;
	void setGlobalPrice(int globalprice);
	void makeCoffe();
	void addMilk();
	bool isReade();
};

class NewCoffeMashine {
public:
	virtual void makePureCoffe() = 0;
	virtual void CoffewithMilk() = 0;
};

class AdapterCoffe :public NewCoffeMashine, protected oldCoffeMashine{
public:
	AdapterCoffe(int coffe=100, int milk=100, int globalprice=0);
	void makePureCoffe();
	void CoffewithMilk();
};

void NewMenu();
void oldMenu();