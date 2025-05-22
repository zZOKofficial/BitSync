#include <bits/stdc++.h>
using namespace std;

int main() {

    string DetSec = "a-b+(c^d*e)";
    stack<char> burger;
    string result;

    for (int i = 0; i < DetSec.length(); i++) {
        char character = DetSec[i];

        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9')) {
            result = result + character;
        } else if (character == '(') {
            burger.push('(');
        } else if (character == ')') {
            while (!burger.empty() && burger.top() != '(') {
                result = result + burger.top();
                burger.pop();
            }
            burger.pop();
        } else {
            while (!burger.empty()) {
                char top = burger.top();

                int topPrecedence;
                if (top == '^')
                    topPrecedence = 3;
                else if (top == '*' || top == '/')
                    topPrecedence = 2;
                else if (top == '+' || top == '-')
                    topPrecedence = 1;
                else
                    topPrecedence = -1;

                int currPrecedence;
                if (character == '^')
                    currPrecedence = 3;
                else if (character == '*' || character == '/')
                    currPrecedence = 2;
                else if (character == '+' || character == '-')
                    currPrecedence = 1;
                else
                    currPrecedence = -1;

                if (currPrecedence <= topPrecedence) {
                    result = result + top;
                    burger.pop();
                } else {
                    break;
                }
            }
            burger.push(character);
        }
    }

    while (!burger.empty()) {
        result = result + burger.top();
        burger.pop();
    }

    cout << "Postfix Expression: " << result << endl;

    return 0;
}