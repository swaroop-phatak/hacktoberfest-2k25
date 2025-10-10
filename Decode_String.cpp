#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string current = "";
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0'); // build the multiplier
        } else if (c == '[') {
            countStack.push(k);
            stringStack.push(current);
            current = "";
            k = 0;
        } else if (c == ']') {
            string temp = current;
            current = stringStack.top();
            stringStack.pop();
            int repeat = countStack.top();
            countStack.pop();
            while (repeat--) current += temp;
        } else {
            current += c;
        }
    }

    return current;
}

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    string decoded = decodeString(s);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
