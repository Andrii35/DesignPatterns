#pragma once
#include<iostream>
#include<string>

using namespace std;

class Car {
	int right;
	int left;
public:
	Car(int right = 1, int left = -1);
	~Car();
	void Start();
	void Stop();
	void Left(int angle);
	void Right(int angle);
	int getRight();
	int getLeft();
	void setLeft(int angle);
	void setRight(int angle);
};



class ICarConsole abstract{
public:
	virtual~ ICarConsole();
	virtual void Stop() = 0;
	virtual void Start() = 0;
	virtual void Rotate(int angle) = 0;

};

class NewCar :public ICarConsole,protected Car {
public:
	NewCar(int left = -1, int right = 1);
	void Stop();
	void Start();
	void Rotate(int angle);
};

class Driver {
	NewCar*newcar;
	Car*oldcar;
public:
	Driver(NewCar*ncar, Car*oc);
	~Driver();
	void Drive();
};