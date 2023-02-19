// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define GLOBALSPACE 5
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v) {
        data = v;
        left = NULL;
        right = NULL;

    }
};
class BST {
public:
    TreeNode* root;
    BST() {
        root = NULL;
    }
    bool isEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    void insertNodeTree(TreeNode* new_node) {
       
        if (root == NULL) {
            root = new_node;
            cout << "Inserted as a root value" << endl;
        }
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (new_node->data == temp->data) {
                    cout << "Not dublicated values allowable, insert another Node" << endl;
                    return;

                }
                else if ((new_node->data < temp->data ) && (temp->left == NULL)) {
                    temp->left = new_node;
                    cout << "value is inserted on the left " << endl;
                    break;
                }
                else if (new_node->data < temp->data) {
                    temp = temp->left;
                }
                else if (new_node->data > temp->data && temp->right == NULL) {
                    temp->right = new_node;
                    cout << "value is inserted on the Right " << endl;
                    break;


                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode* r, int space) { 
        if (r == NULL) return;
        space = space + GLOBALSPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = GLOBALSPACE; i < space; i++) {
            cout << " ";
        }
        cout << r->data<<("\n");
        print2D(r->left, space);
    }
    void traversalTreePreOrder(TreeNode* r) { // root left right
        if (r == NULL) return;
        // print the value of the node
        cout << r->data << endl;
        // Go ahead to the left by a recursive function to pause and continue
        traversalTreePreOrder(r->left);
        // Go ahead to the right by a recursive function to pause and continue
        traversalTreePreOrder(r->right);
    }
    void traversalTreeInOrder(TreeNode* r) { //  left root right
        if (r == NULL) return;
        // Go ahead to the left by a recursive function to pause and continue
        traversalTreeInOrder(r->left);
        // print the value of the  node
        cout << r->data << endl;
       
        // Go ahead to the right by a recursive function to pause and continue
        traversalTreeInOrder(r->right);
    }
    void traversalTreePostOrder(TreeNode* r) { //  left right root
        if (r == NULL) return;
        //1 Go ahead to the left by a recursive function to pause and continue
        traversalTreePostOrder(r->left);
        //2 Go ahead to the right by a recursive function to pause and continue
        traversalTreePostOrder(r->right);
        //3 print the value of the  node
        cout << r->data << endl;
    }
    TreeNode* searchInTree(int val) {
        if (root == NULL) return root;
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (val == temp->data) return temp;
                else if (val < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            return NULL;
        }
    }
    int height(TreeNode* r) {
        if (r == NULL) return -1;
        else {
           int lheight = height(r->left);
           int rheight = height(r->right);
            if (lheight > rheight) return (lheight + 1);
            else return (rheight + 1);
        }
    }
    void printLevelOrderHandler(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++) {
            printLevelOrderBFS(r, i);
        }
    }
    void printLevelOrderBFS(TreeNode* r, int val) {
        if (r == NULL) return;
        else if (val == 0) cout << r->data << " ";
        else {
            printLevelOrderBFS(r->left, val - 1);
            printLevelOrderBFS(r->right, val - 1);

        }
    }
    TreeNode* DeleteNode(TreeNode* r, int val) {
        if (r == NULL) return r;
        else if (val < r->data) {
            r->left = DeleteNode(r->left,val);

        }
        else if (val > r->data) {
            r->right = DeleteNode(r->right, val);
        }
        else{
            if (r->left == NULL) { // only has right child
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) { // only has left child
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else { // has 2 child so we will need to find min node in the right subtree on max for left
                TreeNode* temp = minNodeHandlerRightSubTree(r->right);
                r->data = temp->data;
                r->right = DeleteNode(r->right, temp->data);
            }
        }
        return r;
    
    }
    TreeNode* minNodeHandlerRightSubTree(TreeNode* right_root_sub) {
        TreeNode* current = right_root_sub;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};

int main()
{
    BST obj;
    // to store in the heap not on stack, so we used pointers here to make all data available...
    // during the loop, if we not use it, the data will be broken just fininshing the first iteration.
    int option,val;

    do {
        cout << "Enter an option from 1 to 5, If you want to exit please enter 0" << endl;
        cout << "Enter 1 to Insert" << endl;
        cout << "Enter 2 to Search" << endl;
        cout << "Enter 3 to Delete" << endl;
        cout << "Enter 4 to Print" << endl;
        cout << "Enter 5 to clac the height of the tree" << endl;
        cout << "Enter 6 to Clear Screen" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> option;
        TreeNode* new_node = new TreeNode();
        switch (option)
        {
        case 1:
            cout << "Enter a value of tree node to insert" << endl;
            cin >> val;
            new_node->data = val;
            obj.insertNodeTree(new_node);
            cout<<endl;
            break;
        case 2:
            cout << "Search, Enter a value you want to search" << endl;
            cin >> val;
            new_node = obj.searchInTree(val);
            if (new_node != NULL) cout << "Value is found, successfuly" << endl;
            else  cout << "Unfortunately, Value is not found." << endl;
            break;
        case 3:
            cout << "Enter a vlaue you want to Delete from the tree" << endl;
            cin >> val;
            new_node = obj.searchInTree(val);
            if (new_node != NULL) {
                obj.DeleteNode(obj.root, val);
                cout << "Value Deleted Successfully. ";
            }
            else {
                cout << "Unfortunately,Value is not Deleted. As the value is not found. ";

            }
            break;
            
        case 4:
            cout << "Print" << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            obj.traversalTreePreOrder(obj.root);
            cout << endl;
            obj.traversalTreePreOrder(obj.root);
            cout << endl;
            obj.traversalTreePreOrder(obj.root);
            cout << endl;
            obj.printLevelOrderHandler(obj.root);
            break;
        case 5:
            cout<<"The height is: "<<obj.height(obj.root)<<endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            break;
        }
    } while (option!=0);
    
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
