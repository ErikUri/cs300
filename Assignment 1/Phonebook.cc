#include "Phonebook.h"
#include "Contact.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Phonebook::Phonebook(){
    vector<Contact> contacts;
}



void Phonebook::Add(string name, string number){
    Contact person(name, number);
    contacts.push_back(person);
}

string Phonebook::Search(string name) {
    for(Contact person : contacts) {
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
            contacts.erase(contacts.begin() + i);
            return;
        }
        i++;
    }
}

void Phonebook::List(){
    for(Contact person : contacts) {
        cout << person.getName() << " " << person.getNumber() << "\n";
    }
}

Phonebook::~Phonebook(){
    
}