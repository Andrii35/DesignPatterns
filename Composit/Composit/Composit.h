#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Component abstract{
protected:
	string name;
	int size;
public:
	Component(string name, int size=0);
	string getName()const;
	virtual int getSize()=0;
	virtual~Component();
	virtual void Add(Component*)=0;
	virtual void Remove(int index)=0;
	virtual Component*getChild(int index)=0;
	virtual void Operation()=0;
	

};

class Composite :public Component {
	vector<Component*> tree;
public:
	Composite(string name);
	~Composite();
	void Add(Component*c);
	void Remove(int index);
	Component*getChild(int index);
	void Operation();
	int getSize();
	
};
class Unit :public Component {
	
public:
	Unit(string name, int size);
	void Add(Component*c);
	void Remove(int index);
	Component*getChild(int index);
	void Operation();
	int getSize();
	
};

