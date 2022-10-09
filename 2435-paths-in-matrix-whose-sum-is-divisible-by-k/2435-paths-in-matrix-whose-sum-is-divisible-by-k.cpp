

#define lln long long int

int dx[2]={1,0};

int dy[2]={0,1};

int mod=1e9+7;


class Solution {
public:
    int n,m;
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        n=grid.size();
        
        m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        return find(0,0,grid[0][0]%k,grid,k,dp)%mod;
        
    }
    
    lln find(int i,int j,int rem,vector<vector<int>>& grid, int &k, vector<vector<vector<int>>>&dp){
        
       if(i>=n || j>=m)
             return 0;
         
        if(i==n-1 && j==m-1){
            
            if(rem==0){
              return 1;
            }
            
            return 0;
            
          }
          
          if(dp[i][j][rem]!=-1)
              return dp[i][j][rem];
        
          lln count=0;
        
        
        for(int i1=0;i1<2;i1++){
            
            int x=i+dx[i1];
            
            int y=j+dy[i1];
              
          if(x<n && y<m && x>=0 && y>=0){
              
              int rem1=(rem+grid[x][y])%k;

              count+=find(x,y,rem1,grid,k,dp);
              
              count%=mod;
              
            }
            
          }
          
          return dp[i][j][rem]=count%mod;
        
    }
};

