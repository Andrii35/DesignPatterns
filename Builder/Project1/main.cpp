#include"paterni.h"

int main() {

	NotebookShop *shop = new NotebookShop();
	NotebookBuilder*builder = new Gamer();
	shop->createNotebook(builder);
	builder->getDevice()->Show();
	delete builder;
	builder= new Home();
	shop->createNotebook(builder);
	builder->getDevice()->Show();
	delete builder;
	builder= new Castom();
	shop->createNotebook(builder);
	builder->getDevice()->Show();
	system("pause");
}