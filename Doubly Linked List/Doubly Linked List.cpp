// Doubly Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class DoublyLinkedList {
    struct Node {
        int element;
        Node* next;
        Node* Prev;
    };
public:
    int count;
    Node* first;
    Node* last;
    DoublyLinkedList() {
        count = 0;
        first = last = NULL;
    }
    bool IsEmpty() {
        return count == 0;
    }
    void InsertFirst(int element) {
        Node* newnode = new Node;
        newnode->element = element;
        if (IsEmpty()) {
            first = last = newnode;
            newnode->next = newnode->Prev = NULL;
            count++;
        }
        else {
            newnode->next = first;
            newnode->Prev = NULL;
            first->Prev = newnode;
            first = newnode;
            count++;
        }
    }
    void InsertLast(int element) {
        Node* newnode = new Node;
        newnode->element = element;
        if (IsEmpty()) {
            first = last = newnode;
            newnode->next = newnode->Prev = NULL;
            count++;
        }
        else {
            newnode->next = NULL;
            last->next = newnode;
            newnode->Prev = last;
            last = newnode;
            count++;
        }
    }
    void InsertAtPos(int pos, int element) {
        if (pos <0 || pos>count) {
            cout << "Out Of Range " << endl;
        }
        else {
            Node* newnode = new Node;
            newnode->element = element;
            if (pos == 0) {
                InsertFirst(element);
            }
            else if (pos == count) {
                InsertLast(element);
            }
            else {
                Node* Curr = new Node;
                for (int i = 1; i < pos; i++) {
                    Curr = Curr->next;
                }
                newnode->next = Curr->next;
                Curr->next->Prev = newnode;
                newnode->Prev = Curr;
                Curr->next = newnode;
                count++;
                
               
            }
            
        }
    }
    void ReomveFirst() {
        if (IsEmpty()) {
            cout << "The List Is Empty";
        }
        else if (count == 1) {
            delete first;
            first = last = NULL;
            
            count--;
        }
        else {
            Node* Curr = first;
            first = first->next;
            first->Prev = NULL;
            delete Curr;
            count--;

        }
    }
    void RemoveLast() {
        if (IsEmpty()) {
            cout << "The List Is Empty " << endl;
        }
        else if (count == 1) {
            delete last;
            first = last = NULL;
            count--;
            
        }
        else {
            Node* Curr = last;
            last = last->Prev;
            last->next = NULL;
            delete Curr;
            count--;
        }
    }
    void RemoveItem(int element) {
        Node* Curr = first->next;
        if (count == 0) {
            cout << "The list is empty" << endl;
        }
        else if (first->element == element) {
            ReomveFirst();
            return; 
        }
        else {
            while (Curr != NULL) {
                if (Curr->element == element)
                    break;
                Curr = Curr->next;
            }
            if (Curr == NULL) {
                cout << "The Item not Found, Sorry " << endl;
            }
            else if (Curr->next == NULL) {
                RemoveLast();
                return;
            }
            else {
                Curr->Prev->next = Curr->next;
                Curr->next->Prev = Curr->Prev;
                delete Curr;
                count--;
            }
        }
    }
    

};
int main()
{
    DoublyLinkedList one;
    one.InsertFirst(15);
    one.InsertFirst(15);

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
