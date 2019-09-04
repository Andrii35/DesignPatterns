#include "Proxy.h"

Door::Door()
{
	state = CLOSED;
}

void Door::Open()
{
	state = OPENED;
}

void Door::Close()
{
	state = CLOSED;
}

void Door::ShowStatus()
{
	cout << "Door is " << (state == CLOSED ? "closed" : "opened") << endl;
}
bool Door::getStatus() {
	return state;
}
SecureProxy::SecureProxy()
{
}

SecureProxy::SecureProxy(Door * door_):door(door_)
{
	ifstream in("users.db");
	string log, passw;
	if (in.is_open()) {
		while (!in.eof()) {
			in >> log;
			in >> passw;
			users[log] = passw;
		}
	}
	else {
		cout << "error opening file\n";
	}
}

SecureProxy::~SecureProxy()
{
	delete door;
}

bool SecureProxy::getAuthorisation(LOGIN login, PASSWORD psw) {
	auto it = users.find(login);
	if (it != users.end()) {
		if (it->second == psw) {
			return true;
		}
		
	}
	else return false;
}
void SecureProxy::Open(LOGIN login, PASSWORD psw)
{
	if (door->getStatus() == OPENED) {
		cout << "Doors has been already opened!" << endl;
		//door->ShowStatus();
		return;
	}
	if (getAuthorisation(login,psw)) {
		door->Open();
	}
	else {
		cout << "Acces is denied" << endl;
	}
}

void SecureProxy::Close()
{
	if (door->getStatus() == CLOSED) {
		cout << "Doors has been already closed!" << endl;
		return;
	}
	door->Close();

}
