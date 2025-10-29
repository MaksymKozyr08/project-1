#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToRPN(string expression) {
    stack<char> st;
    string output = "";
    
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        if (isdigit(ch) || ch == '.') {
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                output += expression[i];
                i++;
            }
            output += ' ';
            i--;
        }
        else if (isalpha(ch)) {
            output += ch;
            output += ' ';
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(ch)) {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.push(ch);
        }
    }
    
    while (!st.empty()) {
        output += st.top();
        output += ' ';
        st.pop();
    }
    
    return output;
}

int main() {
    string expression;
    getline(cin, expression);
    
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] != ' ')
            temp += expression[i];
    }
    
    cout << infixToRPN(temp) << endl;
    
    return 0;
}   