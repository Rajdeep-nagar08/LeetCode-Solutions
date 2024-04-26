int dp[201][201];
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
      if(nums[0].size()==1)
        return nums[0][0];
      int mn=INT_MAX;
       memset(dp,-1,sizeof(dp));

      for(int j=0;j<nums[0].size();j++){
        mn=min(mn,find(0,j,nums));
      }
      return mn;
    }
  
   int find(int i,int j,vector<vector<int>>&nums){
     if(i==nums.size())
       return 0;
     if(dp[i][j]!=-1)
       return dp[i][j];
     int mn=INT_MAX;
     for(int k=0;k<nums[0].size();k++){
       if(k!=j)
       mn=min(mn,nums[i][j]+find(i+1,k,nums));
     }
      return dp[i][j]=mn;
   }
};

/*
dp[i][j]=min sum from ith rows jth column to last row
Ans= min(dp[0][j])

dp[i][j]=nums[i][j]+ min(dp[i+1][!j]) !j means any column except j
*/

