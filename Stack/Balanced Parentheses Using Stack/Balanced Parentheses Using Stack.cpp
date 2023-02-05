// Balanced Parentheses Using Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;
bool ArePair(char open, char close) {
    if (open == '(' && close == ')') return true;
    else if (open == '{' && close == '}') return true;
    else if (open == '[' && close == ']') return true;
    return false;
}
bool AreBalanced(string exp) {
    int length = exp.length();
    stack<char>st;
    for (int i = 0; i < length; i++) {
        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            st.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (st.empty() || !ArePair(st.top(), exp[i])) {
                return false;
            }
            else st.pop();
        }
    }
    return st.empty() ? true : false;
}

int main()
{
    std::cout << "Enter a Senetence!\n";
    string exp;
    cin >> exp;
    cout << AreBalanced(exp);
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
