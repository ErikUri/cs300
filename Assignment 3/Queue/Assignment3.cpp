#include <iostream>
#include "QueueStack.h"
using namespace std;

int main(){
	QueueStack<int> myqueue;
	cout<<"Enter a number:";
	int x;
	cin>>x;
	while (x!= 0){
		myqueue.enqueue(x);
		cout<<"Enter a number:";
		cin>>x;
	}
	cout<<myqueue.dequeue()<<endl;
	cout<<myqueue.dequeue()<<endl;
	cout<<myqueue.dequeue()<<endl;
	cout<<myqueue.dequeue()<<endl;
    return 0;


}
