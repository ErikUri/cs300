#include "Phonebook.h"
#include "Contact.h"
#include <string>
#include <vector>
using namespace std;

Phonebook::Phonebook(){
    vector<Contact> contacts;
}



void Phonebook::Add(string name, string number){
    Contact person(name, number);
    contacts.push_back(person);
}

string Phonebook::Search(string name) {
    for(Contact person : contacts) { // search every contact from the top. not efficiant but good enough.
        if (person.getName() == name) {
            return person.getNumber();
        }
    }
    return "Not Found.";
}

void Phonebook::Delete(string name){
    int i = 0;
    for(Contact person : contacts) {
        if (person.getName() == name) {
            contacts.erase(contacts.begin() + i); // same format as search, with added line of code to erase. i keeps track of position.
            return;
        }
        i++;
    }
}

void Phonebook::List(){
    for(Contact person : contacts) {
        printContact(person); // with friend function, all termianl i/o is offloaded to main and conact.
    }
}

Phonebook::~Phonebook(){
    
}