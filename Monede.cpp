#include "Monede.h"
#include <string.h>
#include <stdio.h>

using namespace std;

Monede::Monede()
{
	this->number = 0;
	this->value = 0;
}

Monede::Monede(int number, int value)
{
	this->number = number;
	this->value = value;
}

Monede::Monede(const Monede& m)
{
	this->number = m.number;
	this->value = m.value;
}

Monede::~Monede()
{
	this->number = 0;
	this->value = 0;
}

int Monede::getNumber()
{
	return this->number;
}

int Monede::getValue()
{
	return this->value;
}


void Monede::setNumber(int newNumber)
{
	this->number = newNumber;
}

void Monede::setValue(int newValue)
{
	this->value = newValue;
}

Monede& Monede::operator=(const Monede& m)
{
	this->setNumber(m.number);
	this->setValue(m.value);
	return *this;
}

bool Monede::operator==(const Monede& m)
{
	return ((this->number == m.number) && (this->value == m.value));
}

bool Monede::operator<(const Monede& m)
{
    return (this->value<m.value);
}

std::ostream& operator<<(std::ostream& os, Monede m)
{
	os << m.number << "*" << m.value <<" RON"<< endl;
	return os;
}


std::istream& operator>>(std::istream& is, Monede& m)
{
	is >> m.number >> m.value;
	return is;

}



