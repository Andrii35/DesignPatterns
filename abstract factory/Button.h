#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Element abstract {
	string name;
public:
	Element(string name = "button");
	string Click();
};
class Button abstract:public Element {
public:
	Button(string but = "button");
};
class MacButton :public Button {
public:
	MacButton(string mac="mac button");
};
class WinButton :public Button {
public:
	WinButton(string win = "win button");
};
class CheckBox abstract :public Element {
	public:
		CheckBox(string box = "check box");

};
class MacCheckBox :public CheckBox {
public:
	MacCheckBox(string mac = "mac check box");
};
class WinCheckBox :public CheckBox {
public:
	WinCheckBox(string win = "win check box");
};
class RadioBtn abstract :public Element {
public:
	RadioBtn(string radio = "radio button");

};
class MacRadioBtn :public RadioBtn {
public:
	MacRadioBtn(string mac = "mac radio button");
};
class WinRadioBtn :public RadioBtn {
public:
	WinRadioBtn(string win = "win radio button");
};

__interface GuiElFactory {
public:
	virtual Button*creatButton() = 0;
	virtual CheckBox*creatCheckBox() = 0;
	virtual RadioBtn*creatRadioBtn() = 0;
};

class WinGuiFactory :public GuiElFactory {
	public:
		Button*creatButton();
		CheckBox*creatCheckBox();
		RadioBtn*creatRadioBtn();
};

class MacGuiFactory :public GuiElFactory {
public:
	Button*creatButton();
	CheckBox*creatCheckBox();
	RadioBtn*creatRadioBtn();
}

void Click();