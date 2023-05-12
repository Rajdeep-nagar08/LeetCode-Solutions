/*
we have two choices
either choose or not choose

dp[i]=max cost from [i...n-1]

Ans=dp[0]

dp[i]=max(q[i][0] + dp[i+q[i][0]+1] , dp[i+1])

*/

#define lln long long int
class Solution {
public:
    lln dp[200001]={{0}};

    long long mostPoints(vector<vector<int>>& q) {
        
      return solve(0,q);
    }
  
    lln solve(int i,vector<vector<int>>&q){
      if(i>=q.size())
        return 0;
      
      if(i==q.size()-1)
        return q[i][0];
      
      if(dp[i]!=0)
        return dp[i];
      
      return dp[i]=max(q[i][0]+solve(i+q[i][1]+1,q) , solve(i+1,q));
      
    }
};