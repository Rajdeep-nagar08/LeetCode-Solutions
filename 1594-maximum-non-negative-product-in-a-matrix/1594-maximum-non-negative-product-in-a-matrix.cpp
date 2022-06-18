#define lln long long int
int mod=1e9+7;

class Solution {
public:
    
    int maxProductPath(vector<vector<int>>& grid) {
        
       int n=grid.size();
        
       int m=grid[0].size();
      
        
        /*
        
        dp1[i][j]= max +ve prouct from [0,0] to [i,j]
        
        dp[2][i][j]= min -ve product from [0,0] to [i,j]
        
        
        ans=dp[n-1][m-1]
        
        */
        
        lln dp1[n+1][m+1];
         
        lln dp2[n+1][m+1];
        
        dp1[0][0]=grid[0][0];
        
        dp2[0][0]=grid[0][0];
        
        for(int j=1;j<m;j++){
            dp1[0][j]=grid[0][j]*dp1[0][j-1];
            dp2[0][j]=grid[0][j]*dp2[0][j-1];

        }
        
          for(int i=1;i<n;i++){
            dp1[i][0]=grid[i][0]*dp1[i-1][0];
            dp2[i][0]=grid[i][0]*dp2[i-1][0];

        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]<0){
                    dp1[i][j]=grid[i][j]*min(dp2[i-1][j],dp2[i][j-1]);
                    dp2[i][j]=grid[i][j]*max(dp1[i-1][j],dp1[i][j-1]);
                    
                }
                else{
                 dp1[i][j]=grid[i][j]*max(dp1[i-1][j],dp1[i][j-1]);
                 dp2[i][j]=grid[i][j]*min(dp2[i-1][j],dp2[i][j-1]);
                    
                }
            }
        }
        
        if(dp1[n-1][m-1]<0)
            return -1;
        
        return dp1[n-1][m-1]%mod;
        
    }
};