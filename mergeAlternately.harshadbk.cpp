#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string result = "";
    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
        result += word1[i++];
        result += word2[j++];
    }
  
    while (i < word1.size()) result += word1[i++];
    while (j < word2.size()) result += word2[j++];

    return result;
}

int main() {
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Merged String: " << mergeAlternately(word1, word2) << endl;

    cout << "Example 2: " << mergeAlternately("ab", "pqrs") << endl;
    return 0;
}
