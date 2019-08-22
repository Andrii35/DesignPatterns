#include"Prototyp.h"

Unit* createPrototype::prototypes[3] = { new Archer(), new Mage(), new Swordsman() };
int main() {

	vector<Unit*>team;
	vector<Unit*>team2;
	int numb = 5;
	while (numb != 0) {

		cout << "Choise a warior\n";
		cout << "1. Archer\n";
		cout << "2. Mage\n";
		cout << "3. Swordsman\n";
		cout << "0. Logout\n";
		cin >> numb;
		team.push_back(createPrototype::createPl(TYPE(numb)));
	}
	for (int i = 0; i < team.size(); i++) {
		team2.push_back(team[i]->clone());
	}

	for (auto elem : team2) {
		elem->Play();
		cout << endl;
	}

	system("pause");
}