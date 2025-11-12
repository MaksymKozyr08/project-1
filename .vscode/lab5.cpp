#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

// --- функція для визначення пріоритету оператора ---
int priority(char op) {
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/') return 3;
    if (op == '^') return 4;
    return 0;
}

// --- перевірка асоціативності (true — справа наліво) ---
bool rightAssoc(char op) {
    return op == '^';
}

// --- токенізація ---
vector<string> tokenize(string s) {
    vector<string> t;
    for (size_t i = 0; i < s.size();) {
        if (isspace(s[i])) { i++; continue; }
        if (isdigit(s[i])) {
            string num;
            while (i < s.size() && isdigit(s[i])) num += s[i++];
            t.push_back(num);
        } else {
            t.push_back(string(1, s[i++]));
        }
    }
    return t;
}

// --- інфікс → ОПН ---
vector<string> toRPN(const vector<string> &a) {
    vector<string> out;
    stack<string> st;
    string prev;
    for (size_t i = 0; i < a.size(); i++) {
        string tok = a[i];
        if (isdigit(tok[0])) {
            out.push_back(tok);
        }
        else if (tok == "(") {
            st.push(tok);
        }
        else if (tok == ")") {
            while (st.top() != "(") {
                out.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else { // оператор
            char c = tok[0];
            // унарний + або -
            if ((c == '+' || c == '-') && (i == 0 || prev == "(" || !isdigit(prev[0]))) {
                tok = "u" + tok;
            }

            while (!st.empty() && st.top() != "(") {
                string top = st.top();
                char t = top.back();

                // для унарних операторів у стеку не порівнюємо пріоритет
                if (top.size() > 1 && top[0] == 'u') break;

                if ((rightAssoc(c) && priority(c) < priority(t)) ||
                    (!rightAssoc(c) && priority(c) <= priority(t))) {
                    out.push_back(top);
                    st.pop();
                } else break;
            }
            st.push(tok);
        }
        prev = tok;
    }

    while (!st.empty()) {
        out.push_back(st.top());
        st.pop();
    }
    return out;
}

// --- обчислення ОПН ---
double eval(const vector<string> &rpn) {
    stack<double> st;
    for (auto &x : rpn) {
        if (isdigit(x[0])) {
            st.push(stoi(x));
        } 
        else if (x == "u+") {
            double a = st.top(); st.pop();
            st.push(+a);
        }
        else if (x == "u-") {
            double a = st.top(); st.pop();
            st.push(-a);
        }
        else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            char c = x[0];
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
            else if (c == '^') st.push(pow(a, b));
        }
    }
    return st.top();
}

int main() {
    string s;
    cout << "Введіть вираз: ";
    getline(cin, s);

    auto tokens = tokenize(s);
    auto rpn = toRPN(tokens);

    cout << "\nОбернена польська нотація: ";
    for (auto &t : rpn) cout << t << " ";
    cout << "\n";

    cout << "Результат = " << eval(rpn) << endl;
}
