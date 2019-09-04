#include"driver.h"

int main() {

	Car* BMW=new Car();
	NewCar* Audi=new NewCar();
	Driver first(Audi, BMW);
	first.Drive();




	system("pause");
}