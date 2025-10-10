#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string result = "";
    int n1 = word1.size(), n2 = word2.size();
    int i = 0, j = 0;

    // Merge characters alternately
    while (i < n1 && j < n2) {
        result += word1[i++];
        result += word2[j++];
    }

    // Append remaining characters
    while (i < n1) result += word1[i++];
    while (j < n2) result += word2[j++];

    return result;
}

int main() {
    string word1 = "abc";
    string word2 = "pqr";

    cout << "Merged String: " << mergeAlternately(word1, word2) << endl;
    return 0;
}
