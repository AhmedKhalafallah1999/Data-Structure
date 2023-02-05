// Queue Array Implementation_Linear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int capacity = 100;
struct queue {
    int arr[capacity];
    int front = -1;
    int rear = -1;
    bool IsEmpty() {
        if (front == -1 && rear == -1) return true;
        else return false;
    }
    bool IsFull() {
        if ((rear+1)%capacity == front) return true;
        else return false;
    }
    void enqueue(int Element) {
        if (IsFull()) return;
        else if (IsEmpty()) {
            // initialize to make the front and rear on the first value
            front = rear = 0;
        }
        else {


            rear=(rear+1)%capacity;
        }
        arr[rear] = Element;
    }
    void dequeue() {
        if (IsEmpty()) return;
        else if (front == rear) {
            front = rear = -1;
        }
        else front=(front+1)%capacity;
    }
    int GetFront() {
        if (IsEmpty()) cout << "Empty Queue" << endl;
        else return arr[front];
    }
    void print() {
        for (int i = front; i <= rear; i=(i+1)%capacity) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    queue one;
    one.enqueue(5);
    one.enqueue(6);
    one.enqueue(7);
    one.enqueue(8);
    one.print();
    one.dequeue();
    one.print();
    one.enqueue(1);
    one.print();



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
