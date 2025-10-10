#include <iostream>
#include <string>
using namespace std;


bool isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for uniformity
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}


string reverseVowels(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
 
        while (left < right && !isVowel(s[left])) {
            left++;
        }
      
        while (left < right && !isVowel(s[right])) {
            right--;
        }
        
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = reverseVowels(str);
    cout << "String after reversing vowels: " << result << endl;

    return 0;
}
