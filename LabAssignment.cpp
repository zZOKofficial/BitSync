#include <iostream>
using namespace std;

string encode(string s, int j) {
    string result = "";
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (count == j) {
            char modified = s[i] + 2;
            result = result + modified;
            count = 0;
        } else {
            result = result + s[i];
            count = count + 1;
        }
    }
    return result;
}

int main() {
    string s;
    int j;
    cout << "Enter the string: ";
    getline(cin, s);
    cout << "Enter the integer (j): ";
    cin >> j;
    string encoded = encode(s, j);
    cout << "Converted String: " << encoded << endl;
    return 0;
}