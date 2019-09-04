#include "button.h"

Element::Element(string name):name(name)
{
}
string Element::Click()
{
	return name;
}

Button::Button(string but) :Element(but)
{
}

CheckBox::CheckBox(string box) : Element(box)
{
}

RadioBtn::RadioBtn(string radio) : Element(radio)
{
}

MacButton::MacButton(string mac) : Button(mac)
{
}

WinButton::WinButton(string win) : Button(win)
{
}

MacCheckBox::MacCheckBox(string mac) : CheckBox(mac)
{
}

WinCheckBox::WinCheckBox(string win) : CheckBox(win)
{
}

MacRadioBtn::MacRadioBtn(string mac) : RadioBtn(mac)
{
}

WinRadioBtn::WinRadioBtn(string win) : RadioBtn(win)
{
}

Button * WinGuiFactory::creatButton()
{
	return new WinButton();

}

CheckBox * WinGuiFactory::creatCheckBox()
{
	return new WinCheckBox();
}

RadioBtn * WinGuiFactory::creatRadioBtn()
{
	return new WinRadioBtn();
}

Button * MacGuiFactory::creatButton()
{
	return new MacButton();
}

CheckBox * MacGuiFactory::creatCheckBox()
{
	return new MacCheckBox();
}

RadioBtn * MacGuiFactory::creatRadioBtn()
{
	return new MacRadioBtn();
}

void Click(GuiElFactory*el)
{
	Button *but = el->creatButton();
}

void User(GuiElFactory * obj)
{
	ifstream out("file.txt");
	string fout;
	out >> fout;
	//cout << fout << endl;
	if (fout == "Windows") {
		obj = new WinGuiFactory();
		cout << obj->creatButton()->Click() << endl;
		cout << obj->creatCheckBox()->Click() << endl;
		cout << obj->creatRadioBtn()->Click() << endl;
	}
	else {
		obj = new MacGuiFactory();
		cout << obj->creatButton()->Click() << endl;
		cout << obj->creatCheckBox()->Click() << endl;
		cout << obj->creatRadioBtn()->Click() << endl;
	}
}
