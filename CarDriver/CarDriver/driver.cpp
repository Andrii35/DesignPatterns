#include "driver.h"

Car::Car(int right, int left):right(right),left(left)
{
}

Car::~Car()
{
}

void Car::Start()
{
	cout << "Start a car. Car went.\n";
}

void Car::Stop()
{
	cout << "Car stop\n";

}

void Car::Left(int angle)
{
	if (angle < 0) {
		cout << "Tourn left\n";
	}
}

void Car::Right(int angle)
{
	if (angle >= 0) {
		cout << "Tourn reight\n";
	}
}

int Car::getRight()
{
	return right;
}

int Car::getLeft()
{
	return left;
}

void Car::setLeft(int angle)
{
	left = angle;
}

void Car::setRight(int angle)
{
	right = angle;
}

NewCar::NewCar(int left, int right):Car(right,left)
{
}

void NewCar::Stop()
{
	Car::Stop();

}

void NewCar::Start()
{
	Car::Start();
}

void NewCar::Rotate(int angle)
{
	if (angle >= 0) {
		Car::Right(angle);
	}
	else if (angle < 0) {
		Car::Left(angle);
	}
}

ICarConsole::~ICarConsole()
{
}

Driver::Driver(NewCar * ncar, Car * oc):newcar(ncar),oldcar(oc)
{
}

Driver::~Driver()
{
	delete newcar;
	delete oldcar;
}

void Driver::Drive()
{
	int choice=100;
	int drive = 100;
	cout << "Choise a car.\n";
		cout << "1. New car\n";
		cout << "2. Old car\n";
		cin >> choice;
		switch(choice) {
			case 1: {
				
				while (drive != 9) {
					cout << "Choise an action\n";
					cout << "1. Start\n";
					cout << "2. Stop\n";
					cout << "3. Rotate\n";
					cout << "9. Stop and exit\n";
					cin >> drive;
					switch (drive) {
					case 1: {
						newcar->Start();
						break;
					}
					case 2: {
						newcar->Stop();
						break;
					}
					case 3: {
						int rotate;
						cout << "Enter an angle for rotate: >=0 to right, < 0 to left\n";
						cin >> rotate;
						newcar->Rotate(rotate);
						break;
					}
					
					}
				}
				break;
			}
			case 2: {
				
				while (drive != 0) {
					cout << "Choise an action\n";
					cout << "1. Start\n";
					cout << "2. Stop\n";
					cout << "3. Tourn right\n";
					cout << "4. Tourn left\n";
					cout << "0. Stop and exit\n";
					cin >> drive;
					switch (drive) {
					case 1: {
						oldcar->Start();
						break;
					}
					case 2: {
						oldcar->Stop();
						break;
					}
					case 3: {
						int rotate;
						cout << "Enter an angle for rotate >=0 to right\n";
						cin >> rotate;
						oldcar->Right(rotate);
						break;
					}
					case 4: {
						int rotate;
						cout << "Enter an angle for rotate < 0 to left\n";
						cin >> rotate;
						oldcar->Left(rotate);
						break;
					}
					}
				}
				break;
			}
		}
	
}
