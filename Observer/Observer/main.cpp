#include"observer.h"

int main() {

	
	Product* first=new	Car ("VW", 10000);
	Bayer* b = new UkranianBuyer("Sergiy", first);
	first->Atach(b);
	first->setPrice(6000);

	

	system("pause");
}