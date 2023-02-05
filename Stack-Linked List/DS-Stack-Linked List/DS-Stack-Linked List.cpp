// DS-Stack-Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class stack {
    struct node {
        int item;
        node* next;
    };
    node* top;
public:
    stack() {
        top = NULL;
    }
    void push(int newItem) {
        node* newItemPtr = new node;
        newItemPtr->item = newItem;
        newItemPtr->next = top;
        top = newItemPtr;
    }
    bool IsEmpty() {
        return top == NULL;
    }
    void pop() {
        if (IsEmpty()) {
            cout << "Stack Is Empty";
        }
        else {
            node* temp = new node;
            temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void pop(int& stackTop) {
        if (IsEmpty()) {
            cout << "The Stack Is Empty";
        }
        else {
            stackTop = top->item;
            node* temp = new node;
            temp = top;
            top = top->next;
            temp = temp->next;
            delete temp;
        }
    }
    void GetTop(int& stackTop) {
        if (IsEmpty()) {
            cout << "Linked List Is Empty";
        }
        else {
            stackTop = top->item;
        }

    }
    void print() {
        node* cur;
        cur = top;
        while (cur != NULL) {
            cout << cur->item << " ";
            cur=cur->next;
        }
    }

};

int main()
{
    stack o;
    /*
    o.push(10);
    o.push(20);
    o.push(30);
    o.push(40);
    o.print();
    cout << endl;
    o.pop();
    o.print();
    cout << endl;
    int y;
    o.GetTop(y);
    cout << y;
    cout << endl;
    */
    int z;
    o.push(20);
    o.push(30);
     o.pop(z);
    o.print();
    cout << z;

    

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
