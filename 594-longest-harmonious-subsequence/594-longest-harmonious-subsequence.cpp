class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        int mx=0;
        
        for(int i=0;i<n;i++){
            
            if(mp[nums[i]+1]>0)
                mx=max(mx,mp[nums[i]]+mp[nums[i]+1]);
            
            if(mp[nums[i]-1]>0)
                mx=max(mx,mp[nums[i]]+mp[nums[i]-1]);
            
        }
        
        return mx;
    }
};