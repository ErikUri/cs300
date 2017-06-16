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
    virtual ~Contact();
};

#endif /* CONTACT_H_ */