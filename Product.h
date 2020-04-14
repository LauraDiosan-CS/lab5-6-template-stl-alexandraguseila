#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <iostream>
#include <ostream>
using namespace std;

class Product
{
private:
	int cod;
	char* name;
	int price;
public:
	Product();
	Product(int, const char*, int);
	Product(const Product&);
	~Product();
	int getCod();
	char* getName();
	int getPrice();
	void setCod(int cod);
	void setName(const char* name);
	void setPrice(int price);
	Product& operator=(const Product&);
	bool operator==(const Product&);
	bool operator<(const Product&);
	friend ostream& operator<<(ostream& os, Product);
	friend istream& operator>>(istream& is, Product&);
};



#endif // PRODUCT_H_INCLUDED
