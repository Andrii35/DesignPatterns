#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

class Notebook {
	string name;
	map<string, string> parametr;
public:
	Notebook(string name);
	string getPart(const string&key);
	void setPart(string key, string value);
	void Show();
	bool checkPart(string key);
		
};

class NotebookBuilder abstract {
protected:
	Notebook*device;
public:
	virtual~NotebookBuilder();
	virtual void setMemory()=0;
	virtual void setHDD()=0;
	virtual void setMatrix()=0;
	virtual void setProcessor()=0;
	Notebook* getDevice();


};

class Gamer :public NotebookBuilder {
public:
	Gamer(string name="Gamer notebook");
	void setMemory();
	void setHDD();
	void setMatrix();
	void setProcessor();
};

class Home : public NotebookBuilder {
public:
	Home(string name = "Home notebook");
	void setMemory();
	void setHDD();
	void setMatrix();
	void setProcessor();
};

class Castom : public NotebookBuilder {
public:
	Castom(string name = "Castom notebook");
	void setMemory();
	void setHDD();
	void setMatrix();
	void setProcessor();

};
class NotebookShop {
public:
	void createNotebook(NotebookBuilder *b);
};