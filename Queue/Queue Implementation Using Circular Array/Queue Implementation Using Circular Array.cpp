// Queue Implementation Using Circular Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;
// const int Max_Size = 200;
class Queue_circular {
    int front;
    int rear;
    int length;
    int *arr;
    int Max_Size;
public:
    Queue_circular(int size){
        if (size <= 0) Max_Size = 100;
        else Max_Size = size;
        front = 0;
        rear = Max_Size - 1;
        length = 0;
        arr = new int[Max_Size];
    }
    int IsEmpty() {
        return length == 0;
    }
    int IsFull() {
        return length == Max_Size;
    }
    void AddQueue(int Element) {
        if (IsFull()) cout << "The Queue is Full"<<endl;
        else {
            rear = (rear + 1) % Max_Size;
            arr[rear] = Element;
            length++;
        }
    }
    void DeleteQueue() {
        if (IsEmpty()) cout << "The Queue is Empty"<<endl;
        else {
            front = (front + 1) % Max_Size;
            length--;
        }
    }
    int FrontQueue(){
        assert(!IsEmpty());
        return arr[front];
    }
    int RearQueue() {
        assert(!IsEmpty());
        return arr[rear];
    }
    int SearchQueue(int element) {
        int pos = -1;
        if (IsEmpty()) cout << "There is no Element to search about!" << endl;
        else {
            for (int i = front; i != rear; i = (i + 1) % Max_Size) {
                if (arr[i] == element) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                if (arr[rear] == element) pos = rear;
                else
                    cout << "Not Fond this number" << endl;
            }
            
            
        }
        return pos;
        
            
        
    }

    void PrintQueue() {
        if (IsEmpty()) cout << "There is no Element to Print!"<<endl;
        else {
            for (size_t i = front; i != rear; i = (i + 1) % Max_Size) {
                cout << arr[i] << " ";
            }
            cout << arr[rear];
        }
        cout <<endl<< "Finished"<<endl;
    }
};
int main()
{
    Queue_circular one(4);
    one.AddQueue(10);
   // one.DeleteQueue();
    one.AddQueue(20);
    one.AddQueue(30);
    one.AddQueue(40);
    one.DeleteQueue();
    one.PrintQueue();
    one.AddQueue(10);
    one.PrintQueue();
   cout<< one.SearchQueue(10);
    



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
