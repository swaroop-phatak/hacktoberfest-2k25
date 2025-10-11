#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0, maxCount = 0;

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        maxCount = count;

        // Sliding window approach
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                count++;
            }
            if (isVowel(s[i - k])) {
                count--;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main() {
    Solution obj;
    string s = "abciiidef";
    int k = 3;
    cout << obj.maxVowels(s, k);
    return 0;
}
