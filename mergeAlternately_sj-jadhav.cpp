#include <iostream>
#include <string>
using namespace std;
string mergeAlternately(const string& s1, const string& s2) {
    string result;
    result.reserve(s1.size()+s2.size());
    int i = 0, j = 0;
    while(i<s1.size()||j<s2.size()){
        if(i<s1.size())result.push_back(s1[i++]);
        if(j<s2.size())result.push_back(s2[j++]);
    }
    return result;
}
int main(){
    string str1="abc",str2="pqr";
    cout<<mergeAlternately(str1,str2)<<endl;  
    str1="ab";
    str2="pqrs";
    cout<<mergeAlternately(str1,str2)<<endl;  
    str1="abcd";
    str2="pq";
    cout<<mergeAlternately(str1,str2)<<endl;  
    return0;
}
