#include"FactoryMethod.h"
#include"Header.h"


int main() {
	/*enum TYPE { ARCHER = 1, MAGE, SWORDSMAN };
	vector<Unit*>team;
	int numb = 5;
	while (numb!=0) {
		
		cout << "Choise a warior\n";
		cout << "1. Archer\n";
		cout << "2. Mage\n";
		cout << "3. Swordsman\n";
		cout << "0. Logout\n";
		cin >> numb;
		switch(numb) {
		
		case ARCHER: {
			team.push_back(new Archer());
			break;
		}
		case MAGE: {
			team.push_back(new Mage());
			break;
		}
		case SWORDSMAN:{
			team.push_back(new Swordsman());
			break;
			}
		}
		
	}
	
	for (auto elem : team) {
		 elem->Play();
		 cout << endl;
	}
	for (auto temp : team) {
		delete temp;
	}*/

	/*Unit*player;
	FactoryMethodArcher factoryArcher;
	FactoryMethodMage factoryMage;
	FactoryMethodSwordsman factorySword;
	FactoryMethod* factory[] = { &factoryArcher,&factoryMage,&factorySword };
	
	vector<Unit*>team;
	int numb = 5;
	while (numb != 0) {

		cout << "Choise a warior\n";
		cout << "1. Archer\n";
		cout << "2. Mage\n";
		cout << "3. Swordsman\n";
		cout << "0. Logout\n";
		cin >> numb;
		switch (numb) {

		case ARCHER:

		case MAGE:

		case SWORDSMAN:
			player = factory[numb - 1]->createPlayer();
			team.push_back(player);
		}
	}
		for (auto elem : team) {
			elem->Play();
			cout << endl;
		}
		for (auto temp : team) {
			delete temp;
	}*/
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
	system("pause");
}