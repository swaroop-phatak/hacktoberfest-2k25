#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(const vector<int>& arr){
    vector<int> stackArr;
    stackArr.reserve(arr.size());
    for(int val:arr){
        bool isGone=false;
        if(val>0){
            stackArr.push_back(val);
            continue;
        }
        while(!stackArr.empty()&&stackArr.back()>0){
            if(stackArr.back()<-val){
                stackArr.pop_back();
                continue;
            }else if(stackArr.back()==-val){
                stackArr.pop_back();
                isGone=true;
                break;
            }else{
                isGone=true;
                break;
            }
        }
        if(!isGone)stackArr.push_back(val);
    }
    return stackArr;
}

int main(){
    vector<vector<int>> cases={{5,10,-5},{8,-8},{10,2,-5},{-2,-1,1,2},{1,-1,-2,-2}};
    for(const auto& nums:cases){
        auto ans=asteroidCollision(nums);
        cout<<"[";
        for(size_t i=0;i<ans.size();++i){
            cout<<ans[i]<<(i+1<ans.size()?", ":"");
        }
        cout<<"]"<<endl;
    }
    return 0;
}
