#define lln long long int
class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
      vector<vector<lln>>dp(n+1,vector<lln>(amt+1,0));
      
      for(int i=0;i<=n;i++){
        for(int j=0;j<=amt;j++){
          if(i==0)
          dp[i][j]=0;
          else if(j==0)
          dp[i][j]=1;
         else if(j>=coins[i-1])
            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
          else
            dp[i][j]=dp[i-1][j];
        }
      }
      return dp[n][amt];
    }
};