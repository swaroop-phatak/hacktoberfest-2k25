#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(const string &word1, const string &word2) {
    string result;
    int n1 = word1.length();
    int n2 = word2.length();
    int i = 0, j = 0;

    // Merge characters alternately
    while (i < n1 || j < n2) {
        if (i < n1) result += word1[i++];
        if (j < n2) result += word2[j++];
    }

    return result;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string merged = mergeAlternately(str1, str2);
    cout << "Merged string: " << merged << endl;

    return 0;
}
