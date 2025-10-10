#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int maxVowels(string s, int k) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int count = 0, maxCount = 0;

    
    for (int i = 0; i < k; i++) {
        if (vowels.count(s[i])) count++;
    }
    maxCount = count;

    for (int i = k; i < s.size(); i++) {
        if (vowels.count(s[i])) count++;          
        if (vowels.count(s[i - k])) count--;      
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter window size k: ";
    cin >> k;

    cout << "Maximum number of vowels in a substring of length " << k << " is: "
         << maxVowels(s, k) << endl;
    return 0;
}
