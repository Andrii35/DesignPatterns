#include "paterni.h"

Gamer::Gamer(string name)
{
	device = new Notebook(name);
}

void Gamer::setMemory()
{
	device->setPart("memory", "16 GB");
}

void Gamer::setHDD()
{
	device->setPart("HDD", "500 GB");
}

void Gamer::setMatrix()
{
	device->setPart("matrix", "1000");
}

void Gamer::setProcessor()
{
	device->setPart("processor", "2.4*16");
}

Notebook::Notebook(string name):name(name)
{
}

string Notebook::getPart(const string & key)
{
	if (checkPart(key)) {
		return parametr[key];
	}
	else
		cout << "Value not exist\n";
}

void Notebook::setPart(string key, string value)
{
	if (checkPart(key)) {
		cout << "This exist\n";
	}
	else
		parametr[key] = value;
	
}

void Notebook::Show()
{
	cout << name << ": " << endl;
	for (auto elem : parametr) {
		cout << elem.first << ":::" << elem.second << endl;
	}
}

bool Notebook::checkPart(string key)
{
	return parametr.find(key)!=parametr.end();
}

NotebookBuilder::~NotebookBuilder()
{
}

Notebook* NotebookBuilder::getDevice()
{
	return device;
}

Home::Home(string name)
{
	device = new Notebook(name);
}

void Home::setMemory()
{
	device->setPart("memory", "8 GB");
}

void Home::setHDD()
{
	device->setPart("HDD", "300 GB");
}

void Home::setMatrix()
{
	device->setPart("matrix", "100");
}

void Home::setProcessor()
{
	device->setPart("processor", "1.8*8");
}

Castom::Castom(string name)
{
	device = new Notebook(name);
}

void Castom::setMemory()
{
	string value;
	cout << "Enter a memory value\n";
	cin >> value;
	device->setPart("memory", value);
}

void Castom::setHDD()
{
	string value;
	cout << "Enter a setHDD value\n";
	cin >> value;
	device->setPart("HDD", value);
}

void Castom::setMatrix()
{
	string value;
	cout << "Enter a matrix value\n";
	cin >> value;
	device->setPart("matrix", value);
}

void Castom::setProcessor()
{
	string value;
	cout << "Enter a processor value\n";
	cin >> value;
	device->setPart("processor", value);
}

void NotebookShop::createNotebook(NotebookBuilder * b)
{
	b->setMemory();
	b->setHDD();
	b->setMatrix();
	b->setProcessor();
}
