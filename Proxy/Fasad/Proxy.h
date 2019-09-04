#pragma once
#include<iostream>
#include<string>
#include<map>
#include<fstream>


using namespace std;
enum States{
	CLOSED,
	OPENED
};


__interface IDoor {
public:
	
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void ShowStatus() = 0;
};

class Door :public IDoor {
	bool state;
public:
	Door();
	void Open();
	void Close();
	void ShowStatus();
	bool getStatus();

};
typedef string LOGIN;
typedef string PASSWORD;
class SecureProxy {
	Door*door;
	LOGIN login;
	PASSWORD psw;
	map<LOGIN, PASSWORD>users;
public:
	SecureProxy();
	SecureProxy(Door*door_);
	~SecureProxy();
	bool getAuthorisation(LOGIN login, PASSWORD psw);
	void Open(LOGIN login, PASSWORD psw);
	void Close();
	
};