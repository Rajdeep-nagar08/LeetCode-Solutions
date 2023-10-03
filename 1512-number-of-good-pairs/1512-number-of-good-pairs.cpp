class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        for(int x:nums){
            mp[x]++;
        }
        
        int ans=0;
        
        for(auto it:mp){
            ans+=(it.second*(it.second-1))/2;
        }
        return ans;
    }
};