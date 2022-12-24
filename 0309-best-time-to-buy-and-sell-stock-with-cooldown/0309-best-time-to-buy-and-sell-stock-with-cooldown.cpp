int dp[5001][2][2];
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
      /*
      
      dp[i][!have][!cooldown]=max(dp[i+1][have][!cooldown]-nums[i],dp[i+1][!have][!cooldown])
      dp[i][!have][cooldown]=max(0,dp[i+1][!have][!cooldown]);
      
     dp[i][have][!cooldown]=max(dp[i+1][!have][cooldown]+nums[i],dp[i+1][have][!cooldown])
     dp[i][have][cooldown]=max(dp[i+1][!have][cooldown]+nums[i],dp[i+1][have][!cooldown])
     
     Noted: for have=1, no changes with change in cooldown, becouse i have a stock , i can sell it 
     whenever i want without any boundation of cooldown
      
      */
      
      memset(dp,-1,sizeof(dp));
      
     return solve(0,0,0,nums);
      
    }
  
     int solve(int i,int have,int cool,vector<int>&nums){
       if(i==nums.size())
         return dp[i][have][cool]=0;
       
       if(dp[i][have][cool]!=-1)
         return dp[i][have][cool];
       
       if(!have){
         if(!cool)
         return dp[i][have][cool]=max(solve(i+1,1,0,nums)-nums[i],solve(i+1,0,0,nums));
         
         else
           return dp[i][have][cool]=max(0,solve(i+1,0,0,nums));
       }
       
       else{
        
         return dp[i][have][cool]=max(solve(i+1,0,1,nums)+nums[i],solve(i+1,1,0,nums));
       }
       
     }
};