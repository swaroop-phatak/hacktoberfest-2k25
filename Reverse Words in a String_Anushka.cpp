#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string word;
    stringstream ss(s);

    // Extract words
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse word order
    reverse(words.begin(), words.end());

    // Join words with a single space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}

// -- Example Usage
int main() {
    string s = "  hello   world  ";
    cout << '"' << reverseWords(s) << '"' << endl; // Output: "world hello"
    return 0;
}
