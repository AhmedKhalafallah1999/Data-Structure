// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class node {
public:
    int key;
    int data;
    node* next;
    node* prev;
    node() {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int key, int data) {
        key = key;
        data = data;
        next = NULL;
        prev = NULL;
    }
   
};
class DoublyLinkedList {
public:
    node* head;
    DoublyLinkedList() {
        head = NULL;
    }
    DoublyLinkedList(node* n) {
        head = n;
    }
    // check if node exists using key value

    node* checkIfNodeExists(int key) {
        node* temp = NULL;
        node* ptr = head;
        while (ptr!=NULL) {
            if (ptr->key == key) {
                temp = ptr;
                break;
               
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // Append a node to the list
    void appendNode(node* n) {
        // check if the node exists or not
        if (checkIfNodeExists(n->key) != NULL) cout << "Sorry, this node is exist with the same key value,"<<n->key<< "please change the key value!" << endl;
        else if (head == NULL) {
            head = n;
           
            cout << "The node is linked as a head node" << endl;
        }
        else {
            node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
            cout << "The node is added as in the last node " << endl;
        }
    }
    // preAppend Node
    void preAppendNode(node* n) {
        // check if the node exists or not
        if (checkIfNodeExists(n->key) != NULL) cout << "Sorry, this node is exist with the same key value," << n->key << "please change the key value!" << endl;
        else if (head == NULL) {
            head = n;
            n->next = NULL;
            n->prev = NULL;
            cout << "The node is linked as a head node" << endl;
        }
        else {
            head->prev = n;
            n->next = head;
            head = n;
            cout << "The node is added as in first node " << endl;
        }
    }
    // insert a node after a determined node in the list
    void insertNode(int key, node* n) {
        node* ptr = checkIfNodeExists(key);
        if (ptr == NULL) cout << "Sorry, the key which you want to add after it it doesn't found " << endl;
        else {
            if (checkIfNodeExists(n->key)!=NULL) {
                cout << "Sorry, this node is exist with the same key value," << n->key << "please change the key value!" << endl;
            }
            else {
                n->next = ptr->next;
                n->prev = ptr;
                ptr->next->prev = n;
                ptr->next = n;
                cout << "Nice, the node is added after the key which you enter " << endl;


            }
           
        }
    }
    //  delete node by Key, Unlinked the node
    void deleteNodeByKey(int key) 
    {
        node* ptr = checkIfNodeExists(key);
        if (ptr == NULL) cout << "The key which you want to delete it's node is not found" << endl;
        else {
            if (head == ptr) {
                head = head->next;
                cout << "The node is successfully unlinked" << endl;
            }
            else if (ptr->next == NULL) {
                ptr->prev->next = NULL;
                cout << "The node is now unlinked from the list "<<endl;
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                cout << "The node is now unliked from the linked list" << endl;

            }
        }

    }
    void updateNode(int key, int data) {
        node* temp = checkIfNodeExists(key);
        if (temp) {
            temp->data = data;

        }
        else {
            cout << "The key you want to update it's node's data is not found" << endl;


        }
    }
    void printing() {
        if (head == NULL) {
            cout << "No nodes in SLL" << endl;
        }
        else {
            cout << "Singl list values: ";
            node* temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->data << ") -->";
                temp = temp->next;
            }
        }
    }


};

int main()
{
    DoublyLinkedList obj;
    // to store in the heap not on stack, so we used pointers here to make all data available...
    // during the loop, if we not use it, the data will be broken just fininshing the first iteration.
    int option, val, key, k;

    do {
        cout << "Enter an option from 1 to 5, If you want to exit please enter 0" << endl;
        cout << "Enter 1 to append" << endl;
        cout << "Enter 2 to preappend" << endl;
        cout << "Enter 3 to insertNodeAfter" << endl;
        cout << "Enter 4 to deleteNodeByKey" << endl;
        cout << "Enter 5 to UpdateNodeByKey" << endl;
        cout << "Enter 6 to print" << endl;
        cout << "Enter 7 to Clear Screen" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> option;
        node* n = new node();
        switch (option)
        {
        case 1:
            cout << "Append, Enter a key and value of the node to be append" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->data = val;
            obj.appendNode(n);
            break;
        case 2:
            cout << "PreAppend, Enter a key and value of the node to be Pre-appended" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->data = val;
            obj.preAppendNode(n);
            break;
        case 3:
            cout << "insert, Enter a value and key of the node to be insert after a key you entered first" << endl;
            cin >> k;
            cout << "Enter a value and key of the node to be insert" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->data = val;
            obj.insertNode(k, n);
            break;
        case 4:
            cout << "Delete, Enter a key of the node to be delete" << endl;
            cin >> k;
            obj.deleteNodeByKey(k);
            break;
        case 5:
            cout << "Delete, Enter a key of the node to be updated, with the new value" << endl;
            cin >> key;
            cin >> val;
            obj.updateNode(key, val);
            break;
        case 6:
            obj.printing();
            break;
        case 7:
            system("cls");
            break;
        default:
            break;
        }
    } while (option != 0);
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
