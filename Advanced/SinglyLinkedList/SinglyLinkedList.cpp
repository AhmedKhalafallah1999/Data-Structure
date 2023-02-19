// SinglyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Node {
public:
    int key;
    int val;
    Node* next;
    Node() {
        key = 0;
        val = 0;
        next = NULL;
    }
    Node(int key, int val) {
        key = key;
        val = val;
        next = NULL;
    }
};
class singlyLinkedList {
public:
    Node* head;
    singlyLinkedList(){
        head = NULL;
    }
    singlyLinkedList(Node* n) {
        head = n;
    }
    // check if node exists using key value
    Node* nodeExists(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->key == key) return temp;
            else {
                temp = temp->next;
            }
        }
        return NULL;
    }
    // Append a node to the list

    void prependNode(Node* n){
        if (nodeExists(n->key) != NULL) {
            cout << "Node is already exists with key value: " << n->key << " . Append a nother node with different key" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "The node is added as a head value" << endl;
            }
            else {
                n->next = head;
                head = n;
                cout << "The node is added successfully" << endl;
            }
        }
    }
    void appendNode(Node* n){
        if (nodeExists(n->key) != NULL) {
            cout << "Node is already exists with key value: " << n->key << " . Append a nother node with different key" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "The node is added as a head value" << endl;
            }
            else {
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = n;
                n->next = NULL;
                cout << "The node is added as a last node in the linked list" << endl;

                
            }
        }
    }
    // insert node at a position after a particular node by key
    void insertNode(int key, Node* n) {
        Node* ptr = nodeExists(key);
        if (ptr == NULL) {
            cout << "this key  is not already exists with key value: " << key << " . Add a nother key " << endl;
            return;
        }
        if (nodeExists(n->key) != NULL) {
            cout << "Node is already exists with key value: " << n->key << " . Append a nother node with different key" << endl;
            return;
        }
        else if (head == NULL) {
            head = n;
            cout << "The node is added as a head value" << endl;
        }
        else {
           
         
           n->next = ptr->next;
           ptr->next = n;
           cout << "The node is added as after the key which you added in the linked list" << endl;

            

            }
        
    }
    void deleteNode(int key){
        
        if (head == NULL) {
            cout << "Linked list is already empty " << endl;
        }
        else if (head !=NULL) {
            if (head->key == key) {
                head = head->next;
                cout << "The node now is being unlinked from the list, Congratulations" << endl;
            }
            else {
                Node* temp = NULL;
                Node* prev = head;
                Node* curr = head->next;
                while (curr!= NULL) {
                    if (curr->key == key) {
                        temp = curr;
                       
                        curr = NULL;
                            
                    }
                    else {
                        prev = prev->next;
                        curr = curr->next;
                    }
                }
                if (temp != NULL) {
                    prev->next = temp->next;
                    cout << "The node is now unlinked" << endl;
                }
            }
        }
    }
    void updateNode(int key , int data){
        Node* temp = nodeExists(key);
        if (temp) {
            temp->val = data;
           
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
            Node* temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->val<<") -->";
                temp = temp->next;
            }
        }
    }

};
int main()
{
    singlyLinkedList obj;
    // to store in the heap not on stack, so we used pointers here to make all data available...
    // during the loop, if we not use it, the data will be broken just fininshing the first iteration.
    int option, val,key,k;

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
        Node* n = new Node();
        switch (option)
        {
        case 1:
            cout << "Append, Enter a key and value of the node to be append" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->val = val;
            obj.appendNode(n);
            break;
        case 2: 
            cout << "PreAppend, Enter a key and value of the node to be Pre-appended" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->val = val;
            obj.prependNode(n);
            break;
        case 3:   
            cout << "insert, Enter a value and key of the node to be insert after a key you entered first" << endl;
            cin >> k;
            cout << "Enter a value and key of the node to be insert" << endl;
            cin >> key;
            cin >> val;
            n->key = key;
            n->val = val;
            obj.insertNode(k,n);
            break;
        case 4:   
            cout << "Delete, Enter a key of the node to be delete" << endl;
            cin >> k;
            obj.deleteNode(k);
            break;
        case 5:
            cout << "Delete, Enter a key of the node to be updated, with the new value" << endl;
            cin >> key;
            cin >> val;
            obj.updateNode(key,val);
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
