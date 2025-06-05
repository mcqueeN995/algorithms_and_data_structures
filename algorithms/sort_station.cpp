#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string shuntingYard(string expr) {
    stack<char> ops;
    string output;

    for (char c : expr) {
        if (c == ' ') continue;

        if (isdigit(c)) {
            output += c;
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (ops.top() != '(') {
                output += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else {
            while (!ops.empty() && priority(ops.top()) >= priority(c) + (c == '^')) {
                output += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        output += ops.top();
        ops.pop();
    }

    return output;
}

int main() {
    string expression = "3+4*2/(1-5)^2";
    string rpn = shuntingYard(expression);
    cout << "Infix: " << expression << endl;
    cout << "RPN: " << rpn << endl;
    return 0;
}