int dp[18][1<<19];
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int slots) {
        
        int n=nums.size();
        
        /*
        
        max n = 2*9 = 18
        
        no of slots = 9
        
        for each slot, we use bitmask
        00 = empty
        01 = having one integer
        11 = having 2 integers (slot is full)
        
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,nums,slots);
    
    }
    
    int find(int i,int mask,vector<int>&nums,int slots){
        
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        
        int mx=INT_MIN;
        
        for(int j=0;j<2*slots;j++){
            if((mask & (1<<j))!=0)
                continue;
            int temp=(nums[i]&((j/2)+1));
     mx=max(mx,(temp+find(i+1,mask | (1<<j),nums,slots)));
        }
            
           return dp[i][mask]=mx;
    }
    
};