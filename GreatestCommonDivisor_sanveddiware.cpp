#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenating in both orders gives different results, no common base pattern
        if (str1 + str2 != str2 + str1) return "";

        // Find gcd of lengths
        int gcdLen = gcd((int)str1.size(), (int)str2.size());

        // Return prefix of that gcd length
        return str1.substr(0, gcdLen);
    }
};

int main() {
    Solution sol;
    string str1 = "ABCABC", str2 = "ABC";
    cout << sol.gcdOfStrings(str1, str2);  // Output: "ABC"
    return 0;
}
