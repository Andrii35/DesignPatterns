#include"Fasad.h"

int main() {

	Computer*comp = new Computer();
	Facade*facad = new Facade(comp);
	facad->turnOn();
	cout << endl;
	facad->turnOff();
	cout << endl;
	
	system("pause");
}
