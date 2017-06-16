/*
+-----------------------+
| class Contact         |
+-----------------------+
|                       |
| string name           |
| string number         |
+-----------------------+
| Contact()             |
| Contact(name, number) |
| getName()             |
| getNumber()           |
| friend printContact() |
| ~Contact()            |
|                       |
+-----------------------+
*/

#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>
using namespace std;

class Contact
{
  protected:
    string name;
    string number;

  public:
    Contact();
    Contact(string name, string number);
    string getName();
    string getNumber();
    friend void printContact(Contact contact);
    friend bool operator== (const Contact &c1, const Contact &c2);
    virtual ~Contact();
};

#endif /* CONTACT_H_ */