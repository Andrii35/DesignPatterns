#pragma once
#include<iostream>
using namespace std;
class Computer {
public:
	Computer();
	~Computer();
	void ShowScreen();
	void sentSound();
	void closeAll();
	void showDesctop();
	void isReady();
};

class Facade {
	Computer*c;
public:
	Facade(Computer*c);
	~Facade();
	void turnOn();
	void turnOff();
};
