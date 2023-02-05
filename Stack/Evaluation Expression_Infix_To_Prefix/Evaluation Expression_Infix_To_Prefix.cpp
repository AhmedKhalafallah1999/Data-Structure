// Evaluation Expression_Infix_To_Prefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
// starting with the fuction which convert from Infix To Prefix:
int Priority(char a) {
    if (a == '+' || a == '-') return 1;
    else if (a == '*' || a == '/') return 1;
    else if (a == '^') return 3;
    return 0;
}
string Infix_To_Prefix (string exp) {
    stack<char>st;
    string out="";
    for (int i = 0; i < exp.size(); i++) {
        if (isdigit(exp[i]) || isalpha(exp[i])) {
            out = exp[i] + out;
        }
        else if (exp[i]=='(') {
            st.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (exp[i] != ')') {
                out = st.top() + out;
                st.pop();
            }
            st.pop();
        }
        else {

            if (!st.empty() && Priority(exp[i]) <= Priority(st.top())) {
                st.push(exp[i]);
            }
            st.push(exp[i]);
        }
    }
    while (!st.empty()) {
        out = st.top() + out;
        st.pop();
    }
    return out;
}
// Code For Taking the return value from the previous code to calculate or evaluate the expression to a value:
float Operator(float first_oprand, float second_operand, char c) {
    if (c == '+') {
        return first_oprand + second_operand;
    }
    else if (c == '-') {
        return first_oprand - second_operand;
    }
    else if (c == '*') {
        return first_oprand * second_operand;
    }
    else {
        return first_oprand / second_operand;
    }
}
float Evaluation(string out_exp) {
    stack<float>st;
    int first_operand;
    int second_operand;

    for (int i = out_exp.size() -1; i >=0; i--) {
        if (isdigit(out_exp[i])) {
            st.push(out_exp[i] - '0');
        }
        else {

            first_operand = st.top();
            st.pop();
            second_operand = st.top();
            st.pop();
            float y = Operator(first_operand, second_operand, out_exp[i]);
            st.push(y);

        }
    }
    float out = st.top();
    return out;
}
int main()
{
    cout << "Enter an Expression you want to convert to PreFix" << endl;
    string exp;
    cin >> exp;
    cout << "The converting From Infix to Prefix is ";
    cout << Infix_To_Prefix(exp) << endl;
    cout << "The Value Of calculating the PreFix expression (Evaluation) Is ";
    cout << Evaluation(Infix_To_Prefix(exp));
    return 0;
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
