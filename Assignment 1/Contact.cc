#include "Contact.h"
#include <string>
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

Contact::~Contact()
{

}