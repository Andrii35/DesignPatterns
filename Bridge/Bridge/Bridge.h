#pragma once
#include<iostream>
#include<string>
using namespace std;


class Theme abstract {
protected:
	string color;
public:
	Theme(string color = "white");
	~Theme();
	virtual string getColor() = 0;
};

class Webpage abstract {
protected:
	Theme*th;
public:
	~Webpage();
	Webpage(Theme*th);
	virtual string getContent() = 0;
};

class Dark:public Theme {
	
public:
	Dark(string d = "dark");
	string getColor();
};

class Light :public Theme {
	
public:
	Light(string light = "light");
	string getColor();
};
class Homes :public Webpage {
	string content;
public:
	Homes(Theme*th) : Webpage(th) {}
	string getContent();

};
class About : public Webpage {
	string content;
public:
	About(Theme*th);
	string getContent();
};

class Career :public Webpage {
	string content;
public:
	Career(Theme*th);
	string getContent();
};