#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move left pointer until a vowel is found
        while (left < right && vowels.find(s[left]) == vowels.end())
            left++;
        // Move right pointer until a vowel is found
        while (left < right && vowels.find(s[right]) == vowels.end())
            right--;

        // Swap vowels
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {
    string s = "leetcode";
    cout << reverseVowels(s) << endl;  // Output: leotcede
    return 0;
}
