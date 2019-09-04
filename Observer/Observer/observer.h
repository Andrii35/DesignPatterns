#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Product;
class Bayer abstract {
public:
	virtual void Update(Product*pr) = 0;
};
class Product {
	vector<Bayer*>buyers;
	string name;
	double price;
public:
	Product(string name = "none", double price = 0);
	~Product();
	void Atach(Bayer*b);
	void Detach(Bayer*b);
	double getPrice()const;
	string getName()const;
	void Notify();
	void setPrice(double price);
};

class Car :public Product {
public:
	Car(string name = "BMW", double price = 100000);
};

class UkranianBuyer :public Bayer {
	string name;
	Product*pr;
public:
	UkranianBuyer(string name,Product*pr);
	Product* getProduct();
	void setProduct(Product*pr);
	void Update(Product*pr);
};