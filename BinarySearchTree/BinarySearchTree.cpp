// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;
struct node {
    int info;
    node* left;
    node* right;
};
class binarySearchTree {
public:
    bool isEmpty();
    bool search(int);
    bool searchRec(int);
    void insert(int);
    void remove(int);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int treeHeight();
    int treeNodeCount();
    int treeLeavesCount();
    void clearTree();
    binarySearchTree();
    ~binarySearchTree();
private:
    node* root;
    void clear(node*& p);
    void inorder(node* p);
    void preorder(node* p);
    void postorder(node* p);
    int  height(node* p);
    int max(int x, int y);
    int nodeCount(node* p);
    int leavesCount(node* p);
    void deleteFormTree(node* p);
    bool searchRecPriv(node*, int);

};
binarySearchTree::binarySearchTree() {
    root = NULL;
}
bool binarySearchTree::isEmpty() {
    return (root == NULL);
}
void binarySearchTree::inorderTraversal() {
    inorder(root);
}
void binarySearchTree::preorderTraversal() {
    preorder(root);
}
void binarySearchTree::postorderTraversal() {
    postorder(root);
}
int binarySearchTree::treeHeight()
{
    return height(root);
}
int binarySearchTree::treeNodeCount()
{
    return nodeCount(root);
}
int binarySearchTree::treeLeavesCount()
{
    return leavesCount(root);
}
// #################################################
void binarySearchTree::inorder(node* p) {
    if (root != NULL) {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
       
        
    }
}
void binarySearchTree::preorder(node* p) {
    if (root != NULL) {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);



    }
}
void binarySearchTree::postorder(node* p) {
    if (root != NULL) {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
        
        



    }
}
void binarySearchTree::clear(node*& p) {
    if (p != NULL) {
        clear(p->left);
        clear(p->right);
        delete p;
        p = NULL;


    }
}
void binarySearchTree::clearTree() {
    clear(root);
}
binarySearchTree::~binarySearchTree()
{
    clear(root);
}

int main()
{
    std::cout << "Hello World!\n";
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
