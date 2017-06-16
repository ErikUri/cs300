#include "Passenger.h"
#include <iostream>
#include <string>
using namespace std;

Passenger::Passenger()
{
    first = "";
    last = "";
    address = "";
    number = "";
}

Passenger::Passenger(string first, string last, string address, string number)
{
    this->first = first;
    this->last = last;
    this->address = address;
    this->number = number;
}

string Passenger::getFirst()
{
    return this->first;
}

string Passenger::getLast()
{
    return this->last;
}

string Passenger::getAddress()
{
    return this->address;
}

string Passenger::getNumber()
{
    return this->number;
}

void Passenger::list()
{
    cout << first + " " + last + " [" + address + "] " + "[" + number + "] " + "\n";
}

bool Passenger::operator== (Passenger & person)
{
	if (getFirst() == person.getFirst() && getLast() == person.getLast())
		return true;
	return false;
}

bool Passenger::operator!= (Passenger & person)
{
	if (getFirst() != person.getFirst() || getLast() != person.getLast())
		return true;
	return false;
}

bool Passenger::operator< (Passenger & person)
{
	if (getLast() <= person.getLast())
		return true;
	return false;
}

Passenger::~Passenger()
{

}