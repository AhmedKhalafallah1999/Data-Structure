// Ds-Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this code to build a data structure called stack

#include <iostream>
using namespace std;
const int Max_Size = 100;
// we can used templete for be aviaiable for all data types
// template<class t> 
class stack {
    int top;
    int item[Max_Size];
public:
    // constructor to initialize the top 
    stack () {
        top = -1;
    }
    // This push function for adding items
    void push(int NewItem) {
        if (top >= 100 - 1) {
            cout << "the stack is full"<<endl;
        }
        else {
            // we increased the top by one every time to make the top on the last element added
            top++;
            item[top] = NewItem;
        }
    }
    // THis function used for check the stack
    bool IsEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
     }
    // THis function used for delete the last in element from stack

    void pop() {
        if (IsEmpty()) {
            cout << "The Stack Is Empty";
        }
        else {
            top--;
        }
    }
    // THis function used for delete the last in element from stack after store it's value in a parameter with pointer

    void pop(int &Element) {
        if (IsEmpty()) {
            cout << "The Stack Is Empty";
        }
        else {
            Element = item[top];
            top--;
        }
    }
    // THis function used for get the last in element from stack

    void GetTop(int& stackTop) {
        if (IsEmpty()) {
            cout << "The Stack Is Empty";
        }
        else {
            stackTop = item[top];
            cout << stackTop << endl;
        }
    }
    void print() {
        for (int i = top; i >= 0; i--) {
            cout << item[i] << " ";
        }
    }
};

int main()
{
    stack o;
   // o.push(5);
   // o.push(10);
  //  o.push(15);
    
    //o.pop();
    //int y;
    //o.pop(y);
    //cout << y;
    //o.GetTop(y);
    // o.push(20);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
