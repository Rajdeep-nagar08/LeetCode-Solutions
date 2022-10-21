#define lln long long int
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n= nums.size();
        
        vector<pair<lln,int>>v(n);
        
        for(int i=0;i<n;i++){
            v[i]={nums[i],i};
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n-1;i++){
           
            if(v[i].first==v[i+1].first && (abs(v[i].second-v[i+1].second)<=k))
                return true;
            
        }
        return false;
    }
};