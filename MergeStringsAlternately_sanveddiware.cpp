#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;

        // Alternate characters from both strings
        while (i < word1.size() && j < word2.size()) {
            result += word1[i++];
            result += word2[j++];
        }

        // Append remaining characters (if any)
        while (i < word1.size()) result += word1[i++];
        while (j < word2.size()) result += word2[j++];

        return result;
    }
};

int main() {
    Solution s;
    string word1 = "abc", word2 = "pqr";
    cout << s.mergeAlternately(word1, word2); // Output: apbqcr
    return 0;
}
