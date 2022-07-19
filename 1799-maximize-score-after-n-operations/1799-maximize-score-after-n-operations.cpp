/*

Please notice that n <= 7 which is very small, we can bruteforce try all possible ways by using mask, and cache the computed result with Top Down DP approach.

Let dp(op, mask) is the maximum score you can receive after performing op operations, where mask represent the indices of nums we already used (ith bit = 1 means we used nums[i]).

Then dp(1, 0) is our answer.

The base case: return 0 when op == n+1, we reach n opeartions.

Transition state:

Choose pair index of (i, j) from [0..2*n-1], where nums[i] and nums[j] hasn't been used yet.
newMask = (1 << i) | (1 << j) | mask # Mark nums[i] and nums[j] as used!
score = dp(op+1, newMask) + op * gcd(nums[i], nums[j])
Choose maximum score between possible scores.

*/


class Solution {

public:
    int dp[8][1<<14]={};

    int maxScore(vector<int>& nums) {
     
      return find(nums,0,1);
      
    }
  
    int find(vector<int>&nums,int mask,int op){
      if(op>nums.size()/2)
        return 0;
      
      if(dp[op][mask])
        return dp[op][mask];
      
      for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
          if(((mask>>j)&1) || ((mask>>i)&1))
              continue;
          
            int newmask=(1<<i)|(1<<j)|mask;
            
            int score=op*__gcd(nums[i],nums[j])+find(nums,newmask,op+1);
            
            dp[op][mask]=max(score,dp[op][mask]);
          }
      }
       return dp[op][mask];
    }
};