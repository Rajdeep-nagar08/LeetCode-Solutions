/*
if top mo

*/


double dp[101][101];
class Solution {
public:
    double champagneTower(int total, int row, int col) {
        if(total<1)
            return 0.00000;
        
        dp[0][0]=total*1;
        
        for(int i=1;i<=row;i++){
         for(int j=0;j<=i;j++){
             if(j==0)
dp[i][j]=max(0.5*(dp[i-1][j]-1),0.0);
             else if(j==i)
dp[i][j]=max(0.5*(dp[i-1][j-1]-1),0.0);
             else if(i-1>=0 && j-1>=0)
dp[i][j]=max(0.5*(dp[i-1][j]-1),0.0)+max(0.5*(dp[i-1][j-1]-1),0.0);
         }
        }
    
        if(dp[row][col]>1)
            return 1.00000;
        return dp[row][col]*1.00000;
    }
};
