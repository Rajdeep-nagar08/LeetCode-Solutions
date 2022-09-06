#define un unsigned int
class Solution {
public:
   
int numDistinct(string s, string t) 
    {
    
        int n=s.size();
        int m=t.size();
    
    
         vector<vector<un>> dp(n+1,vector<un>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1; //subsequence mil gya h 
    }
    for(int j=1;j<m+1;j++){
        dp[0][j]=0; // nhi mila h 
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s[i-1]==t[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
         
        }
    }
    
    
    return dp[n][m];
    
  }
 
};