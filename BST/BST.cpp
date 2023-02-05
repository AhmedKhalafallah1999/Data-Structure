// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include <cassert>
using namespace std;
class BST {
private:
    struct node {
        int data;
        node* left;
        node* right;

    };
    node* root = nullptr;
    // helper for the add function by using recursion
    void addHelper(node* temp, int value) {
        if (value <= temp->data) {
            if (temp->left = nullptr) {
                node* newNode = new node;
                newNode->data = value;
                newNode->left = nullptr;
                newNode->right = nullptr;
                temp->left = newNode;
            }
            else {
                addHelper(temp, value);
            }
        }
        else {
            if (value > temp->data) {
                if (temp->right = nullptr) {
                    node* newNode = new node;
                    newNode->data = value;
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    temp->right = newNode;
                }
                else {
                    addHelper(temp, value);
                }
            }
        }
    }
    // helper for the getMax function by using recursion
    int getMaxHelper(node* temp) {
        if (temp->right == nullptr) {
            return temp->data;
        }
        else {
            return getMaxHelper(temp->right);
        }

    }
    // helper for the getMin function by using recursion
    int getMinxHelper(node* temp) {
        if (temp->left == nullptr) {
            return temp->data;
        }
        else {
            return getMaxHelper(temp->left);
        }

    }
    // helper for the getHeight function by using recursion
    int getHeightHelper(node* temp) { 
        if (temp == nullptr) {
            return -1;
        }
       
            int left_subTree = getHeightHelper(temp->left);
            int right_subTree = getHeightHelper(temp->right);

            return 1 + max(left_subTree, right_subTree);
        
    }

public:
    // iterations add
    void add(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        node* temp = root;
        node* parent = nullptr;
        while (temp != nullptr) {
            parent = temp;
            if (value <= temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (value <= parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
        // recursion method
    }
    // recursion method
    void addRecursion(int value) {
        if (root == nullptr) {
            node* newNode = new node;
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;

            root = newNode;
        }
        else {
            addHelper(root, value);
        }
    }
    // function to get the maximum number #Iterative method
    int getMax() {
        node* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp->data;

    }
    // function to get the minimum number #Iterative method
    int getMin() {
        node* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp->data;

    }
    // function to get the maximum number #Recursion method
    int getMaxRecursion() {
        return getMaxHelper(root);
    }
    // function to get the maximum number #Recursion method
    int getMinRecursion() {
        return getMinxHelper(root);
    }
    // function to get the height number #Recursion method
    int getHeight() {
        if (root == nullptr) {
            return -1;
        }
        else {
            return getHeightHelper(root);
        }
    }

};
int main()
{
    BST obj;
    obj.add(15);
    obj.add(6);
    obj.add(3);
    obj.add(9);
    obj.add(8);
    obj.add(20);
    obj.add(25);
    cout << obj.getHeight();

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
