#include "Flightbook.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "***Alaska Airlines***";

    Flightbook flights;
    int flight;
    string first, last, address, number;

    while (true)
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
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter first name:";
            cin.ignore();
            getline(cin, first);
            cout << "Enter last name: ";
            getline(cin, last);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter phone: ";
            getline(cin, number);
            flights.Add(flight, first, last, address, number);
            cout << endl;
        }
        break;
        case 'S':
        case 's':
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter first name: ";
            cin.ignore();
            getline(cin, first);
            cout << "Enter last name: ";
            getline(cin, last);
            flights.Search(flight, first, last);
            break;
        case 'D':
        case 'd':
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter first name: ";
            cin.ignore();
            getline(cin, first);
            cout << "Enter last name: ";
            getline(cin, last);
            flights.Delete(flight, first, last);
            break;
        case 'L':
        case 'l':
            cout << "Enter flight number: ";
            cin >> flight;
            flights.List(flight);
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