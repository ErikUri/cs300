#include "Flightbook.h"
#include "Passenger.h"
#include "FlightLinkedList.h"
#include <string>
#include <iostream>
using namespace std;

Flightbook::Flightbook()
{
    FlightLinkedList<Passenger> flight100, flight200, flight300, flight400;
    FlightLinkedList<Passenger> *flightptr;
}

void Flightbook::SwitchFlight(int flight)
{
    switch (flight)
    {
    case 100:
        flightptr = &flight100;
        break;
    case 200:
        flightptr = &flight200;
        break;
    case 300:
        flightptr = &flight300;
        break;
    case 400:
        flightptr = &flight400;
        break;
    default:
        cout << "\nInvalid flight. Try 100, 200, 300 or 400.\n";
        flightptr = NULL;
        break;
    }
}

void Flightbook::Add(int flight, string first, string last, string address, string number)
{
    Passenger person(first, last, address, number);
    SwitchFlight(flight);
    flightptr->insert(person);
}

string Flightbook::Search(int flight, string first, string last)
{
    Passenger * person = new Passenger(first, last, "", "");
    SwitchFlight(flight);
    person = flightptr->search(*person); // this is like pulling the rug out from underneath yourself with variables.
    if(person == NULL) {
        cout << "\nNot Found.\n";
    } else {
        person->list();
    }
}

void Flightbook::Delete(int flight, string first, string last)
{
    Passenger * person = new Passenger(first, last, "", "");
    SwitchFlight(flight);
    person = flightptr->search(*person); // this is like pulling the rug out from underneath yourself with variables.
    if(person == NULL) {
        cout << "\nNot Found.\n";
    } else {
        flightptr->remove(*person);
    }
}

void Flightbook::List(int flight)
{
    SwitchFlight(flight);
    flightptr->list();
}

Flightbook::~Flightbook()
{
}