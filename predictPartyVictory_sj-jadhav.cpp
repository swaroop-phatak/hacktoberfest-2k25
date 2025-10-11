#include <iostream>
#include <queue>
#include <string>
using namespace std;

string predictPartyVictory(const string& senate) {
    int n=senate.size();
    queue<int>radiant,dire;
    for(int i=0;i<n;++i){
        if(senate[i]=='R')radiant.push(i);
        else dire.push(i);
    }
    while(!radiant.empty()&&!dire.empty()){
        int r=radiant.front();radiant.pop();
        int d=dire.front();dire.pop();
        if(r<d)radiant.push(r + n);
        else dire.push(d + n);
    }
    return radiant.empty()?"Dire":"Radiant";
}

int main(){
    string s;
    if(!(cin >>s))  return 0;
    cout<<predictPartyVictory(s)<<endl;
    return 0;
}
