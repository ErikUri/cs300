#include "LinkedStack.h"
#include <iostream>
#include <string>
using namespace std;

void add(string a, string b);

int main()
{
    string expression;
    LinkedStack<char> stack_1, stack_2, stack_3;
    char ch = ' '; // did not think about evaluating values / casting, only have chars...

    cout << "enter a expression: \n";
    cin >> expression;
    for (int i = 0; i <= expression.length(); i++)
    {
        ch = expression[i];
        if (ch == '+' || ch == '*')
        {
            stack_1.push(ch); // 3
        }
        else if (ch == '(' || ch == ')')
        {
            // do nothing
        }
        else
        {
            stack_2.push(ch); // 1
        }
    }
    while (!stack_1.isEmpty())
    {
        ch = stack_1.pop();
        stack_3.push(ch);
    }
    while (!stack_2.isEmpty())
    {
        ch = stack_2.pop();
        stack_3.push(ch);
    }
    cout << "postfix: ";
    while (!stack_3.isEmpty())
    {
        ch = stack_3.pop();
        cout << ch; // read out values, reset to evaluate
        stack_2.push(ch);
    }
    cout << '\n';
    while (!stack_2.isEmpty())
    {
        ch = stack_2.pop();
        stack_1.push(ch);
    }

    add("1876543217", "8292");
    return 0;
}

void add(string y, string z)
{
    LinkedStack<int> stack_1, stack_2, stack_3;

    int digit = 0;
    int maxLength;
    if (y.length() > z.length())
        maxLength = y.length();
    else
        maxLength = z.length();
    for (int i = 0; i <= y.length(); i++)
    {
        digit = y[i];
        stack_1.push(digit);
    }
    for (int i = 0; i <= z.length(); i++)
    {
        digit = z[i];
        stack_2.push(digit);
    }

    char x;
    int a, b, c, d, carry;
    stack_1.pop();
    stack_2.pop();
    carry = 0;

    cout << "sum = ";
    for (int i = 0; i < maxLength; i++)
    {
        if (!stack_1.isEmpty()) {
            x = stack_1.pop();
            a = x - '0';
        } else {
            a = 0;
        }

        if (!stack_2.isEmpty()) {
            x = stack_2.pop();
            b = x - '0';
        } else {
            b = 0;
        }
        c = a + b;

        if (c < 10)
        {
            d = c + carry;
            stack_3.push(d);
            carry = 0;
        }
        else
        {
            c = c % 10;
            d = c + carry;
            stack_3.push(d);
            carry = 1;
        }
    }
    while (!stack_3.isEmpty())
    {
        c = stack_3.pop();
        cout << c;
    }
    cout << "\n";
}