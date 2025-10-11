#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                resultStack.push(currentString);
                k = 0;
                currentString = "";
            } else if (c == ']') {
                string decodedString = resultStack.top();
                resultStack.pop();
                int currentK = counts.top();
                counts.pop();

                for (int i = 0; i < currentK; i++) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += c;
            }
        }
        return currentString;
    }
};

int main() {
    Solution solution;
    string encoded = "3[b2[ca]]";
    cout << "Decoded string: " << solution.decodeString(encoded) << endl;
    return 0;
}
