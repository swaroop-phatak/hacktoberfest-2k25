int maximum(vector<int>&piles){
    int maxi=-1;
    int n=piles.size();
    for(int i=0 ; i<n ; i++){
        maxi = max(maxi,piles[i]);
    }
    return maxi;
}
long long timetaken(vector<int>&piles , int k){
    long long totalh=0;
    int n=piles.size();
    for(int i=0 ; i<n ; i++){
        totalh += ceil(double(piles[i])/(double)k);
    }
    return totalh;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=maximum(piles);
        int low=1 , high=maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(timetaken(piles,mid)<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
