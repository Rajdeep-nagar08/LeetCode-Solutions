
int dp[51][51];
class Solution {
public:
    int n,m;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
    
        n=grid.size();
        
        m=grid[0].size();
        
        int mn=INT_MAX;
        
        memset(dp,-1,sizeof(dp));
        
        for(int c=0;c<m;c++){
            int ans=grid[0][c]+find(1,c,grid,cost);
            mn=min(mn,ans);
        }
        
        return mn;
        
    }
    
      int find(int r,int prevCol,vector<vector<int>>&grid,vector<vector<int>>& cost){
          if(r==n)
              return 0;
          
          if(dp[r][prevCol]!=-1)
              return dp[r][prevCol];
                        
              int mn=INT_MAX;
          
          for(int c=0;c<m;c++){
              mn=min(mn,grid[r][c]+cost[grid[r-1][prevCol]][c]+find(r+1,c,grid,cost));
          }
          
          return dp[r][prevCol]=mn;
      }
};

