/*
 * LinkedStack.h
 *
 *  Created on: May 5, 2017
 *      Author: fatma.serce
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>*next;
};

template <class T>
class LinkedStack{
	private:
		node<T>* top;
	public:
		LinkedStack();
		bool isEmpty();
		void push(T&);
		T pop();
		T stop();
		void destroy();
		~LinkedStack();
};
template <class T>
LinkedStack<T>::LinkedStack(){
    top = NULL;
}
template <class T>
bool LinkedStack<T>::isEmpty(){
    return top == NULL;
}
template <class T>
void LinkedStack<T>::push(T& item){
    node<T>* newNode = new node<T>;
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}
template <class T>
T LinkedStack<T>::pop(){
    if(!isEmpty()){
    	node<T>* p;
    	p = top;
    	top = top->next;
    	T data = p->data;
    	delete p;
    	return data;
    }else{
    	cout<<"empty stack";
    }
}
template <class T>
T LinkedStack<T>::stop(){
    if(!isEmpty()){
    	return top->data;
    }else{
    	cout<<"empty stack";
    }
}
template <class T>
void LinkedStack<T>::destroy(){
     node<T>* p ;
     while(top!=NULL){
    	 p = top;
    	 top = top->next;
    	 delete p;
     }
}
template <class T>
LinkedStack<T>::~LinkedStack(){
	top = NULL;
}














#endif /* LINKEDSTACK_H_ */
