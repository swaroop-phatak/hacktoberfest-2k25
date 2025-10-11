#include <iostream>
#include <string>
#include <algorithm>

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(std::string s, int k) {
        int currentVowelCount = 0;
        
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                currentVowelCount++;
            }
        }
        
        int maxVowelCount = currentVowelCount;
        
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i - k])) {
                currentVowelCount--;
            }
            if (isVowel(s[i])) {
                currentVowelCount++;
            }
            maxVowelCount = std::max(maxVowelCount, currentVowelCount);
        }
        
        return maxVowelCount;
    }
};

int main() {
    Solution sol;
    std::string s1 = "abciiidef";
    int k1 = 3;
    std::cout << "Input: s = \"" << s1 << "\", k = " << k1 << std::endl;
    std::cout << "Output: " << sol.maxVowels(s1, k1) << std::endl; // Expected: 3

    std::string s2 = "aeiou";
    int k2 = 2;
    std::cout << "\nInput: s = \"" << s2 << "\", k = " << k2 << std::endl;
    std::cout << "Output: " << sol.maxVowels(s2, k2) << std::endl; // Expected: 2

    std::string s3 = "leetcode";
    int k3 = 3;
    std::cout << "\nInput: s = \"" << s3 << "\", k = " << k3 << std::endl;
    std::cout << "Output: " << sol.maxVowels(s3, k3) << std::endl; // Expected: 2

    return 0;
}
