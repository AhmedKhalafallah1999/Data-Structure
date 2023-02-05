// Queue Using Linked List With Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Queue>
using namespace std;
class LinkedQueue {
private:
    struct node {
        int item;
        node* next;
        
      };
    node* front;
    node* rear;
    int length;
public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
        length = 0;
    }
    bool IsEmpty() {
       // if (front == NULL && rear == NULL) return true;
        return length == 0;
    }
    void enqueue(int item) {
        node* newitem = new node;
        newitem->item = item;
        newitem->next = NULL;
        if (length == 0) {
            front = rear = newitem;
        }
        else {
            rear->next = newitem;
            rear = newitem;
        }
        length++;
    }
    void dequeue() {
        if (IsEmpty()) cout << "The Queue is Empty";
        else if(length==1) {
            delete front;
            rear = NULL;
            length = 0;
        }
        else {
            node* temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    }
    int GetFront() {
        if (!IsEmpty()) {
            return front->item;
        }
    }
    void ClearQueue() {
        node* temp;
        while (front != NULL) {
            temp = front;
            front = front->next;
            delete temp;

        }
        rear = NULL;
        length = 0;
    }
    void Display() {
        node* temp=front;
        while (temp != NULL) {
            cout << temp->item<<" ";
            temp = temp->next;
        }
    }
    void Search(int item) {
        node* temp = front;
        bool flaq = true;
        if (IsEmpty()) {
            cout << "Empty Queue";
           
        }
        else {
            
            while (temp != NULL) {
                if (temp->item == item) {
                    cout << "The Item is " << item<<"found";
                    flaq = false;
                    break;
                }
                temp = temp->next;
            }
            if (flaq) cout << "The item you search is not found" << endl;
        }
        
        
    }


};

int main()
{
    LinkedQueue one;
    one.enqueue(10);
    one.enqueue(20);
    one.enqueue(30);
    one.enqueue(40);
    one.Display();
    cout << endl;
    one.dequeue();
    one.Display();
    cout << endl;
    one.Search(100);
    cout << endl;
    cout<<one.GetFront();
    cout << endl;
    one.ClearQueue();
    one.Display();

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
