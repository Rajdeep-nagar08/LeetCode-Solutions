class Solution {
public:
    int numSquares(int n) {
        

      /*
      Either take j*j to sum or not (choices availale, think of dp)
      
      dp[i]=least no of perfect squares that sum to i
      ANS=dp[n]
      dp[0]=0;
      
      dp[i]=min(dp[i],dp[i-j*j]+1)  (i=1 to i=n) and (j=1 to j*j<=i)
      
      */
      
      vector<int>dp(n+1,INT_MAX);
      dp[0]=0;
      
      for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
          dp[i]=min(dp[i],dp[i-j*j]+1);
        }
      }
      
      return dp[n];
      
    }
};


