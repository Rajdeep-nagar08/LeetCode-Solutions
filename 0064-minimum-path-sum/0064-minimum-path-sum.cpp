/*

dp[i][j] = min path sum from [i,j] to [n-1,m-1]


*/


int dp[201][201];

class Solution {
public:
    
  
    
    int minPathSum(vector<vector<int>>& grid) {
       
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,grid);
        
    }
    
    int find(int i, int j, vector<vector<int>>& grid){
    
        if((i==grid.size() && j>=grid[0].size()-1) || (i==grid.size()-1 && j==grid[0].size()))
            return 0;
           
           if(i>=grid.size() || j>=grid[0].size())
           return 200001;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int sum1=200001;
        
            sum1=min(sum1,grid[i][j]+find(i+1,j,grid));
            
        
        int sum2=200001;
        
            sum2=min(sum2,grid[i][j]+find(i,j+1,grid));
        
        
        return dp[i][j]=min(sum1,sum2);
    }
        
        
        
        
};