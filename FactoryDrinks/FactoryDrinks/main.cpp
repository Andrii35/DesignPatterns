#include"FactoryHeader.h"

ColaFactory*ColaFactory::cocacola = 0;
PepsiFactory*PepsiFactory::drink = 0;

int main() {

	string name;
	cout << "Enter your name\n";
	cin >> name;
	Client first(name);
	ColaFactory*coca = ColaFactory::getCocacola();
	PepsiFactory*pepsi = PepsiFactory::getDrink();
	
	first.Factory(coca, pepsi);


	system("pause");
}