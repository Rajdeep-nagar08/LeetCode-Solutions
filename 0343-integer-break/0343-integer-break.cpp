#define lln long long int

class Solution {
public:
    int integerBreak(int n) {
      if(n==2)
        return 1;
      if(n==3)
        return 2;
      vector<lln>dp(n+1);
      
      for(int i=0;i<=n;i++)
         dp[i]=i;
    
      for(int i=4;i<=n;i++){
        for(int j=1;j<=i;j++){
          dp[i]=max(dp[i],dp[i-j]*j);
        }
      }
      return dp[n];
    }
};

/*

dp[i]=max product of no's that sum to i
Ans=dp[n] as given i>=2
Base case :dp[2]=1
either we choose a no or not choose it 
dp[i]=max(dp[i],dp[i-j]*j)  (i=2 to n) and (j=1 to i-1) 
*/