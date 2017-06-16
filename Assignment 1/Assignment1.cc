#include "Phonebook.h"
#include "Contact.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "***MY PHONEBOOK APPLICATION***";

    Phonebook contacts;
    string name, first, last, number; // variables for user interface.

    ifstream f;
    f.open("phonebook.txt"); // import file and dump into vector.
    while (!f.eof())
    {
        f >> first >> last >> number;
        contacts.Add((first+' '+last), number);
    }
    f.close();

    while (true) // user interface, switch statement while true, q to exit.
    {
        cout << "Please choose an operation:\nA(Add) | S (Search) | D(Delete) |L(List) |Q(Quit): ";
        char ch;

        if (!cin.get(ch))
            break;

        switch (ch)
        {
        case 'A':
        case 'a':
        {
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter phone: ";
            cin >> number;
            contacts.Add(name, number);
            cout << endl;
        }
        break;
        case 'S':
        case 's':
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Phone number: " << contacts.Search(name) << endl
                 << endl;
            break;
        case 'D':
        case 'd':
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            contacts.Delete(name);
            cout << endl;
            break;
        case 'L':
        case 'l':
            contacts.List();
            cout << endl;
            break;
        case 'Q':
        case 'q':
            return 0;
            break;
        default:
            cout << "\nPlease, try again.\n";
        }
    }
}