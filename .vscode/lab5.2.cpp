#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// функція, що повертає пріоритет операторів
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string toRPN(const string& expr) {
    stack<char> st;    
    string output = "";

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            while (isdigit(c)) {
                output += c;
                i++;
                if (i >= expr.size()) break;
                c = expr[i];
            }
            output += ' ';
            i--; 
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.push(c);
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
    string expr;
    cout << "Введіть вираз: ";
    getline(cin, expr);
    string rpn = toRPN(expr);
    cout << "Обернен польська нотація: " << rpn << endl;
    return 0;
}
