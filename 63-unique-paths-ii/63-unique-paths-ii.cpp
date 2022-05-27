#define lln long long int
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
    
        int n= obstacleGrid.size(); 
        
        int m= obstacleGrid[0].size(); 
        
    
        lln dp[n][m];

        if(obstacleGrid[n-1][m-1]==1) 
            return 0;
    
        for(int i=n-1; i>=0; i--){
            if(obstacleGrid[i][m-1]==0) 
                dp[i][m-1]=1;
            else{
                while(i>=0) {
                    dp[i][m-1]=0;
                    i--;
                }
            }
        }
        
        for(int i=m-1; i>=0; i--){
            if(obstacleGrid[n-1][i]==0) 
                dp[n-1][i]=1;
            else{
                while(i>=0) {
                    dp[n-1][i]=0;
                    i--;
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(obstacleGrid[i][j]==1) 
                    dp[i][j]=0;
                else
                    dp[i][j]= dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    
};