// Exp 1: Designing and Validating a Context Free Grammar

#include <iostream>
#include <string>

using namespace std;

bool isValidNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

bool isValidProduction(const string& production) {
    if (production.empty())
        return false;

    if (production == "ε")
        return true;

    for (char ch : production) {
        if (!(islower(ch) || isupper(ch) || ch == 'ε'))
            return false;
    }

    return true;
}

bool validateGrammar(const string& rule) {
    size_t arrowPos = rule.find("->");

    if (arrowPos == string::npos) {
        cout << "Invalid: Missing '->' in the production rule." << endl;
        return false;
    }

    string lhs = rule.substr(0, arrowPos);
    string rhs = rule.substr(arrowPos + 2);

    while (!lhs.empty() && lhs.front() == ' ')
        lhs.erase(lhs.begin());
    while (!lhs.empty() && lhs.back() == ' ')
        lhs.pop_back();

    while (!rhs.empty() && rhs.front() == ' ')
        rhs.erase(rhs.begin());
    while (!rhs.empty() && rhs.back() == ' ')
        rhs.pop_back();

    if (lhs.length() != 1 || !isValidNonTerminal(lhs[0])) {
        cout << "Invalid: Left-hand side must contain exactly one non-terminal." << endl;
        return false;
    }

    if (!isValidProduction(rhs)) {
        cout << "Invalid: Right-hand side is not a valid production." << endl;
        return false;
    }

    return true;
}

void displayResult(const string& rule, bool valid) {
    if (valid)
        cout << "Valid production rule." << endl;
}

int main() {
    string rule;

    cout << "Enter a production rule: ";
    getline(cin, rule);

    bool valid = validateGrammar(rule);

    displayResult(rule, valid);

    return 0;
}