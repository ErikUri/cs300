#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Phonebook
{
  private:
	std::vector<Contact> contacts;
  public:
    Phonebook();
    void Add(string name, string number);
    string Search(string name);
    void Delete(string name);
    void List();
    virtual ~Phonebook();
};

#endif /* PHONEBOOK_H_ */