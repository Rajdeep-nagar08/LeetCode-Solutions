class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) 
    {
        
       
        int n=nums.size();
        
        /*
        
        nums[j]=nums[i]+c*space
        
        nums[i]=nums[j]-c*space
        
        clearly
        
        nums[i]=nums[j]%space
        
        count of such nums[j] should be max to max
        
        returning min. nums[i]
        
        */
        
        unordered_map<int,int>mp;
        
        int mxC=INT_MIN;
        
        for(int x:nums){
            mp[x%space]++;
            mxC=max(mxC,mp[x%space]);
        }
        
        int ans=INT_MAX;
        
        for(int x:nums){
            if(mp[x%space]==mxC)
               ans=min(ans,x);
        }
        
        return ans;
    }
};