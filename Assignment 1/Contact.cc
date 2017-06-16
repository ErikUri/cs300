#include "Contact.h"
#include <string>
#include <iostream>
using namespace std;

Contact::Contact()
{
    name = "";
    number = "";
}

Contact::Contact(string name, string number)
{
    this->name = name;
    this->number = number;
}

string Contact::getName()
{
    return this->name;
}

string Contact::getNumber()
{
    return this->number;
}

void printContact(Contact contact){
    cout << contact.name << " " << contact.number << "\n"; // friend function, but unfortunatly now Contact does i/o.
}

bool operator== (const Contact &c1, const Contact &c2)
{
    return (c1.name == c2.name); // overloaded operator.
}

Contact::~Contact()
{

}