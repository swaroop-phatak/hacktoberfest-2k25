#include <iostream>
#include <string>
using namespace std;

// Helper function to expand around center
int expandAroundCenter(const string &s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++;    // found a palindrome
        left--;
        right++;
    }
    return count;
}

int countPalindromicSubstrings(const string &s) {
    int total = 0;
    for (int i = 0; i < s.length(); i++) {
        // Odd-length palindromes
        total += expandAroundCenter(s, i, i);
        // Even-length palindromes
        total += expandAroundCenter(s, i, i + 1);
    }
    return total;
}

int main() {
    string s1 = "abc";
    string s2 = "aaa";

    cout << "Palindromic substrings in \"" << s1 << "\": " << countPalindromicSubstrings(s1) << endl;
    cout << "Palindromic substrings in \"" << s2 << "\": " << countPalindromicSubstrings(s2) << endl;

    return 0;
}
