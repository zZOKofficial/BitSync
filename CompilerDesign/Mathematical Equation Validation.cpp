#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '=';
}

bool isOperand(char ch) {
    return isalnum(ch);
}

bool validation(string exp)
{
    stack<char> st;
    bool expectOperand = true;
    bool hasAssignment = false;
    bool firstToken = true;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == ' ') continue;

        if (!isOperand(ch) && !isOperator(ch) && ch != '(' && ch != ')')
        {
            cout << "Error: Invalid character '" << ch << "'.\n";
            return false;
        }

        if (ch == '(') {
            if (!expectOperand) {
                cout << "Error: Missing operator before opening parenthesis.\n";
                return false;
            }
            st.push(ch);
            expectOperand = true;
            firstToken = false;
        }
        else if (ch == ')') {
            if (st.empty()) {
                cout << "Error: Unmatched closing parenthesis.\n";
                return false;
            }
            if (expectOperand) {
                cout << "Error: Unexpected closing parenthesis.\n";
                return false;
            }
            st.pop();
            expectOperand = false;
            firstToken = false;
        }
        else if (isOperator(ch)) {
            if (expectOperand) {
                cout << "Error: Unexpected operator '" << ch << "'.\n";
                return false;
            }

            if (ch == '=') {
                if (hasAssignment) {
                    cout << "Error: Multiple assignment operators ('=') found.\n";
                    return false;
                }
                if (!st.empty()) {
                    cout << "Error: Assignment '=' cannot be inside parentheses.\n";
                    return false;
                }
                hasAssignment = true;
            }

            expectOperand = true;
            firstToken = false;
        }
        else if (isOperand(ch)) {
            if (!expectOperand) {
                cout << "Error: Missing operator between operands.\n";
                return false;
            }



            while (i + 1 < exp.length() && isOperand(exp[i + 1])) {
                i++;
            }

            expectOperand = false;
            firstToken = false;
        }
    }

    if (expectOperand) {
        cout << "Error: Expression cannot end with an operator.\n";
        return false;
    }

    if (!st.empty()) {
        cout << "Error: Unmatched opening parenthesis.\n";
        return false;
    }

    return true;
}

int main () {
    while (true) {
        string expression;
        cout << "Enter expression:\n";
        getline(cin, expression);

        if (validation(expression)) {
            cout << "Expression is VALID.\n";
        } else {
            cout << "Expression is INVALID!\n";
        }
    }
    return 0;
}
