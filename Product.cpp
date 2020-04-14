#include "Product.h"
#include <string.h>
#include <stdio.h>

using namespace std;

Product::Product()
{
	this->cod = 0;
	this->price = 0;
	this->name = NULL;
}

Product::Product(int cod, const char* name, int price)
{
	this->cod = cod;
	this->price = price;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Product::Product(const Product& e)
{
	this->cod = e.cod;
	this->price = e.price;
	this->name = new char[strlen(e.name) + 1];
	strcpy(this->name, e.name);
}

Product::~Product()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->cod = 0;
	this->price = 0;
}

int Product::getPrice()
{
	return this->price;
}

int Product::getCod()
{
	return this->cod;
}

char* Product::getName()
{
	return this->name;
}

void Product::setCod(int newCod)
{
	this->cod = newCod;
}

void Product::setPrice(int newPrice)
{
	this->price = newPrice;
}

void Product::setName(const char* newName)
{
	if (this->name)
		delete[] this->name;
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}


Product& Product::operator=(const Product& e)
{
	this->setCod(e.cod);
	this->setName(e.name);
	this->setPrice(e.price);
	return *this;
}

bool Product::operator==(const Product& e)
{
	return ((this->cod == e.cod) && (this->price == e.price) && (strcmp(this->name, e.name) == 0));
}

std::ostream& operator<<(std::ostream& os, Product e)
{
	os << e.cod << " " << e.name << " " << e.price << endl;
	return os;
}


std::istream& operator>>(std::istream& is, Product& p)
{
	if (p.name == NULL)
		p.name = new char[20];
	is >> p.cod >> p.name >> p.price;
	return is;

}




