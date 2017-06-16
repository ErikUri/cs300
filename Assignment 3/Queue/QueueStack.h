#include <iostream>
#include "LinkedStack.h"
using namespace std;
template <class T>
class QueueStack
{
    LinkedStack<T> s1;
    LinkedStack<T> s2;

  public:
    void enqueue(T &item);
    T dequeue();
};
template <class T>
void QueueStack<T>::enqueue(T &item)
{
    while(!s1.isEmpty()){
        T temp = s1.pop();
        s2.push(temp);
    }
    s1.push(item);
    while(!s2.isEmpty()){
        T temp = s2.pop();
        s1.push(temp);
    }
}
template <class T>
T QueueStack<T>::dequeue()
{
    return s1.pop();
}