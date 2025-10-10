#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++; // Move in s only if characters match
        }
        j++; // Always move in t
    }
    return i == s.size(); // All characters in s matched
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t)) cout << "s is a subsequence of t\n";
    else cout << "s is NOT a subsequence of t\n";

    return 0;
}
