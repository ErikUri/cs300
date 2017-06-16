#include <iostream>
#include "LinkedList.h" 
using namespace std;

int main(){

	LinkedList<int> mylist;
	cout<<"Enter a number:";
	int x;
	cin>>x;
	while (x!= 0){
		mylist.insert_last(x);
		cout<<"Enter a number:";
		cin>>x;
	}
	cout<<mylist.findNth(2)<<endl;
	cout<<mylist.middle();
	mylist.reverse();
	cout<<mylist.findNth(1)<<endl;
	cout<<mylist.findNth(2)<<endl;
	cout<<mylist.findNth(3)<<endl;
    return 0;


}
