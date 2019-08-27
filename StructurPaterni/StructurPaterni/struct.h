#pragma once
#include<iostream>
#include<string>

using namespace std;
//Wrapper or Adapter

class Rectangle  {
	int x;
	int y;
	int x2;
	int y2;
public:
	Rectangle(int x, int y, int x2, int y2);
	void Draw();
};

class NewRectangle abstract{
protected:
	string color;

public:
	
	NewRectangle(string color="yellow");
	virtual void Draw() = 0;
};

class RectangleAdapter:public NewRectangle, protected Rectangle {
public:
	void Draw();
	RectangleAdapter(string color,int x, int y, int w, int h);
};


