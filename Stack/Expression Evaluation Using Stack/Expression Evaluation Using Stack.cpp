// Expression Evaluation Using Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int Priority(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    return 0;
}
string infix_to_Postfix(string exp) {
    stack<char>st;
    string output = "";
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == ' ') continue;
        if (isdigit(exp[i]) || isalpha(exp[i])) {
            output += exp[i];
        }
        else if (exp[i] == '(') {
            st.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (st.top() != '(') {
                output += st.top();
                st.pop();
            }
            st.pop();

        }
        else {
            while (!st.empty() && Priority(exp[i]) <= Priority(st.top())) {
                output += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }


    }
    while (!st.empty()) {
        output += st.top();
        st.pop();
    }
    return output;
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
    
    for (int i = 0; i < out_exp.size(); i++) {
        if (isdigit(out_exp[i])) {
            st.push(out_exp[i]-'0');
        }
        else  {
            
                second_operand = st.top();
                st.pop();
                first_operand = st.top();
                st.pop();
                float y = Operator(first_operand,second_operand,out_exp[i]);
                st.push(y);
            
        }
    }
    float out = st.top();
    return out;
}
int main()
{
    cout << "Enter an Expression you want to convert to PostFix" << endl;
    string exp;
    cin >> exp;
    cout << "The converting From Infix to PostFix is ";
    cout << infix_to_Postfix(exp)<<endl;
    cout << "The Value Of calculating the PostFix expression (Evaluation) Is ";
    cout<<Evaluation(infix_to_Postfix(exp));
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
