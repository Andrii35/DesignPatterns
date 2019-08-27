#include"Bridge.h"

int main() {

	Webpage*p = new About(new Dark());
	cout<<p->getContent()<<endl;
	delete p;
	p = new Homes(new Dark());
	cout << p->getContent();
	system("pause");
}