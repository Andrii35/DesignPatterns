#pragma once

#include<iostream>
#include<string>
using namespace std;

class Paint abstract {
protected:
	string color;
public:
	Paint(string color = "white");
	virtual void DrowRect()=0;
	~Paint();

};

class Figure abstract {
protected:
	Paint*brush;
public:
	Figure(Paint*br);
	virtual void Drow() = 0;
	~Figure();
	
};
class BlueRect:public Paint {

};
class RedRect:public Paint {

};
class Rectangle {

};
class Ellipse {

};