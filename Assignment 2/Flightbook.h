#ifndef FLIGHTBOOK_H_
#define FLIGHTBOOK_H_

#include "Passenger.h"
#include "FlightLinkedList.h"
#include <string>
#include <iostream>
using namespace std;

class Flightbook
{
private:
  FlightLinkedList<Passenger> flight100, flight200, flight300, flight400;
  FlightLinkedList<Passenger> *flightptr;
  void SwitchFlight(int flight);

public:
  Flightbook();
  void Add(int flight, string first, string last, string address, string number);
  string Search(int flight, string first, string last);
  void Delete(int flight, string first, string last);
  void List(int flight);
  virtual ~Flightbook();
};

#endif /* FLIGHTBOOK_H_ */