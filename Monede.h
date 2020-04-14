#ifndef MONEDE_H_INCLUDED
#define MONEDE_H_INCLUDED
#include <iostream>
#include <ostream>
using namespace std;

class Monede
{
private:
	int number;
	int value;
public:
	Monede();
	Monede(int, int);
	Monede(const Monede&);
	~Monede();
	int getNumber();
	int getValue();
	void setNumber(int);
	void setValue(int);
	Monede& operator=(const Monede&);
	bool operator==(const Monede&);
	bool operator<(const Monede&);
	friend ostream& operator<<(ostream& os, Monede);
	friend istream& operator>>(istream& is, Monede&);
};



#endif // PRODUCT_H_INCLUDED

