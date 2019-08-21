#pragma once
#include<iostream>
#include<string>
using namespace std;

 class Toy abstract {
	 string name;
 public:
	 Toy(string name = "none");
	 void Print();
};

 class Bear : public Toy {
 public:
	 Bear(string n="bear");
};
 class Cat : public Toy {
 public:
	 Cat(string n="cat");
 };
 class TeddyCat :public Cat {
 public:
	 TeddyCat();
 };
 class WoodenCat :public Cat {
 public:
	 WoodenCat();
 };
 class TeddyBear :public Bear {
 public:
	 TeddyBear();
 };
 class WoodenBear :public Bear {
 public:
	 WoodenBear();
 };

 __interface ToysFactory{
	 public:
	virtual Bear* createBear()=0;
	virtual Cat* creatCat()=0;
 };

 class WoodenToys:public ToysFactory{
 public:
	 Bear* createBear();
	 Cat* creatCat();
 };
 class TeddyToys :public ToysFactory {
 public:
	 Bear* createBear();
	 Cat* creatCat();
 };

 void UseToys(ToysFactory*obj);