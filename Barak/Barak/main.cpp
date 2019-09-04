#include"barak.h"

Weapon*Prototyp::prototyp[3] = { new Gun(),new Mashingun(),new Blade() };


//сама реалізація гри ще трохи не дописані за браком часу, але патерні реалізовані.
int main() {

	vector<Unit*>player1;
	vector<Unit*>player2;
	vector<Weapon*>forpl1;
	vector<Weapon*>forpl2;
	Play (player1,player2,forpl1,forpl2);
	

	system("pause");
}