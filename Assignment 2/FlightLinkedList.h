#ifndef FLIGHTLINKEDLIST_H_
#define FLIGHTLINKEDLIST_H_
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

template <class T>
struct flight_node
{
	Passenger data;
	flight_node *next;
};

template <class T>
class FlightLinkedList : public LinkedList<T>
{
  protected:
	flight_node<T> *head, *last;
	int count;

  public:
	FlightLinkedList();
	bool is_empty();
	int length();
	void insert(T &);
	T *search(T &);
	void remove(T &);
	void list();

	void destroy_list();
	virtual ~FlightLinkedList();
};

//initializing the list: constructor
template <class T>
FlightLinkedList<T>::FlightLinkedList()
{
	head = NULL;
	last = NULL;
	count = 0;
}
//check if list is empty
template <class T>
bool FlightLinkedList<T>::is_empty()
{
	return head == NULL;
}

//get the number of nodes in the list
template <class T>
int FlightLinkedList<T>::length()
{
	return count;
}

//insert a new item in the list
template <class T>
void FlightLinkedList<T>::insert(T &item)
{
	flight_node<T> *q, *p;
	flight_node<T> *current = new flight_node<T>;
	current->data = item;
	current->next = NULL;
	if (head == NULL)
	{
		head = last = current;
	}
	else if (item < head->data)
	{
		current->next = head;
		head = current;
	}
	else if (last->data < item)
	{
		last->next = current;
		last = current;
	}
	else
	{
		p = NULL;
		q = head;
		while (q->data < item)
		{
			p = q;
			q = q->next;
		}
		p->next = current;
		current->next = q;
	}
	count++;
}
// search function
template <class T>
T *FlightLinkedList<T>::search(T &item)
{
	flight_node<T> *temp = head;
	while (temp != NULL && temp->data != item)
	{
		temp = temp->next;
	}
	if (temp != NULL)
		return &temp->data;
	return NULL;
}

//delete function
template <class T>
void FlightLinkedList<T>::remove(T &item)
{
	flight_node<T> *p, *q;
	if (head == NULL)
		cout << "List is empty..." << endl;
	else if (head->data == item)
	{
		p = head;
		head = head->next;
		delete p;
		count--;
		if (head == NULL)
			last = NULL;
	}
	else
	{
		p = head;
		q = head->next;
		while (q != NULL && q->data != item)
		{
			p = q;
			q = q->next;
		}
		if (q == NULL)
			cout << "item is not found";
		else
		{
			p->next = q->next;
			if (q->next == NULL)
				last = p;
			delete q;
			count--;
		}
	}
}

template <class T>
void FlightLinkedList<T>::list()
{
	flight_node<T> *temp = head;
	while (temp != NULL)
	{
		temp->data.list();
		temp=temp->next;
	}
	return;
}

template <class T>
void FlightLinkedList<T>::destroy_list()
{
	flight_node<T> *p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

//destructor
template <class T>
FlightLinkedList<T>::~FlightLinkedList()
{
	destroy_list();
}

#endif /* FLIGHTLINKEDLIST_H_ */