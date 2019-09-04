#include"Composit.h"

int main() {

	Component*root = new Composite("root");
	Component*f1 = new Composite("folder1");
	Component*f2 = new Composite("folder2");
	Component*leaf1 = new Unit("file1.txt", 12);
	Component*leaf2 = new Unit("file2.jpg",14);
	Component*leaf3 = new Unit("file3.db",10);
	root->Add(f1);
	root->Add(f2);
	f1->Add(leaf1);
	f2->Add(leaf2);
	f2->Add(leaf3);
	root->Operation();

	system("pause");
}