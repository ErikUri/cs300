#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
#include <string>
using namespace std;

class Passenger
{
protected:
  string first, last, address, number;

public:
  Passenger();
  Passenger(string first, string last, string address, string number);
  string getFirst();
  string getLast();
  string getAddress();
  string getNumber();
  void list();
  virtual ~Passenger();
  bool operator== (Passenger &person);
	bool operator!= (Passenger &person);
	bool operator< (Passenger &person);
};

#endif /* PASSENGER_H_ */