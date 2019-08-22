#include"FactoryMethod.h"

int main() {
	vector<Unit*>team;
	int numb = 5;
	while (numb != 0) {

		cout << "Choise a warior\n";
		cout << "1. Archer\n";
		cout << "2. Mage\n";
		cout << "3. Swordsman\n";
		cout << "0. Logout\n";
		cin >> numb;

		team.push_back(FactoryMethod::createPlayer(TYPE(numb)));
	}
	for (auto elem : team) {
		elem->Play();
		cout << endl;
	}
	for (auto temp : team) {
		delete temp;
	}
}