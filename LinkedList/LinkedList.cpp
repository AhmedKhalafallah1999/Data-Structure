// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class linkedList {
    struct Node {
        int item;
        Node* next;
    };
    Node* first;
    Node* last;
    int length;
public:
    linkedList() {
        first = last = NULL;
        length = 0;
    }
    bool IsEmpty() {
        return length == 0;
    }
    void InsertFront(int element) {
        Node* newnode = new Node;
        newnode->item = element;
        if (IsEmpty()) {
            newnode->next = NULL;
            first = last = newnode;
        }
        else {
            newnode->next = first;
            first = newnode;
        }
        length++;
    }
    void InsertEnd(int element) {
        Node* newnode = new Node;
        newnode->item = element;
        if (IsEmpty()) {
            newnode->next = NULL;
            first = last = newnode;
        }
        else {
            newnode->next = NULL;
            last->next = newnode;
            last = newnode;
        }
        length++;
    }
    void InsertAtIndex(int pos, int element) {
        if (pos<0 || pos >length) {
            cout << "Out Of Range";
        }
        else {
            Node* newnode = new Node;
            newnode->item = element;
            if (pos == 0) {
                InsertFront(element);
            }
            else if (pos == length) {
                InsertEnd(element);
            }
            else {
                Node* Curr = first;
                for (int i = 1; i <pos; i++) {
                    Curr = Curr->next;
                }
                newnode->next = Curr->next;
                Curr->next = newnode;
                length++;
            }

        }
    }
    void print() {
        Node* Curr = first;
        while (Curr != NULL) {
            cout << Curr->item << " ";
            Curr = Curr->next;
        }
    }
    void RemoveFirst() {
        if (IsEmpty()) {
            cout << "The List Is Empty";
        }
        else if (length == 1) {
            first = last = NULL;
            length--;
        }
        else {
            Node* Curr = first;
            first = first->next;
            delete Curr;
            length--;
        }
    }
    void RemoveLast() {
        if (IsEmpty()) {
            cout << "The List Is Empty";
        }
        else if (length == 1) {
            delete first;
            first = last = NULL;
            length--;
        }
        else {
            Node* Curr = first->next;
            Node* Prev = first;
            while (Curr != last) {
                Prev = Curr;
                Curr = Curr->next;

            }
            delete Curr;
            Prev->next = NULL;
            last = Prev;
            length--;
        }
    }
    void RemoveItem(int item) {
        if (IsEmpty()) {
            cout << "The List Is Empty";
        }
        else if (first->item == item) {
            Node* Curr = first;
            first = first->next;
            delete Curr;
            length--;
            if (length == 0) last = NULL;
        }
        else  {
            Node* Curr = first->next;
            Node* Prev = first;
            while (Curr != NULL) {
                if (Curr->item == item) {
                    break;
                }
                Prev = Curr;
                Curr = Curr->next;
            }
            if (Curr == NULL) cout << "Element not found";
            else {
                Prev->next = Curr->next;
                 if (last == Curr) {
                    last = Prev;
                }
                delete Curr;
                length--;
            }

        }
    }
    void reserve() {
        Node* Prev = new Node;
        Node* Curr = new Node;
        Node* Next = new Node;
        Prev = NULL;
        Curr = first;
        Next = Curr->next;
       // Curr->next = Prev;
        while ( Next!=NULL) {
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        first = Prev;
       // last = NULL;
    }
    int search(int element) {
        Node* Curr = new Node;
        Curr = first;
        int pos = 0;
        while (Curr != NULL) {
            if (Curr->item == element) 
                return pos;
            Curr = Curr->next;
            pos++;
            
        }
        return -1;
    }

};

int main()
{
    linkedList A;
    A.InsertFront(5);
    A.InsertFront(555);
    A.InsertFront(5555);
    A.print();
    cout << endl;
    A.InsertAtIndex(2, 1000);
    A.print();
    cout << endl;
    A.reserve();
    A.print();
    cout << endl;
    cout<<A.search(555);
    cout << A.search(55555);

   

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
