#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(string s, int k) {
    int count = 0, maxCount = 0;

    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) count++;
    }

    maxCount = count;

    for (int i = k; i < s.size(); i++) {
        if (isVowel(s[i])) count++;        
        if (isVowel(s[i - k])) count--;    
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    string s = "abciiidef";
    int k = 3;
    cout << "Maximum number of vowels in a substring of length " << k << ": "
         << maxVowels(s, k) << endl;

    return 0;
}
