
#define lln long long int

lln dp1[16][16];

lln dp2[16][16];

int mod=1e9+7;

int dx[2]={1,0};
int dy[2]={0,1};


class Solution {
public:
    int n,m;
    int maxProductPath(vector<vector<int>>& grid) {
       
        n=grid.size();
        
        m=grid[0].size();
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp1[i][j]=1e18;
                dp2[i][j]=1e18;
            }
        }
        
        lln ans;
        
        if(grid[0][0]>=0)
        ans=(grid[0][0]*findMax(0,0,grid))%mod;
        else
        ans=(grid[0][0]*findMin(0,0,grid))%mod;
            
        
        if(ans<0)
            return -1;
        
        return ans;
        
    }
    
      lln findMax(int i,int j,vector<vector<int>>&grid){
          
          if(i==n-1 && j==m-1){
              return 1;
          }
          
          if(dp1[i][j]!=1e18)
              return dp1[i][j];
          
         lln mx=-1e18;
          
          for(int i1=0;i1<2;i1++){
              
              int x1=i+dx[i1];
              int y1=j+dy[i1];
              
              if(x1>=0 && y1>=0 && x1<n && y1<m){

                 if(grid[x1][y1]>=0)
                  mx=max(mx,grid[x1][y1]*findMax(x1,y1,grid));
                  else
                  mx=max(mx,grid[x1][y1]*findMin(x1,y1,grid));
                  
              }
                  
          }
          
          return dp1[i][j]=mx;
     }
    
    
     lln findMin(int i,int j,vector<vector<int>>&grid){
          
          if(i==n-1 && j==m-1){
              return 1;
          }
          
          if(dp2[i][j]!=1e18)
              return dp2[i][j];
          
          lln mn=1e18;
          
          for(int i1=0;i1<2;i1++){
              
              int x1=i+dx[i1];
              int y1=j+dy[i1];
              
              if(x1>=0 && y1>=0 && x1<n && y1<m){

                 if(grid[x1][y1]<=0)
                  mn=min(mn,grid[x1][y1]*findMax(x1,y1,grid));
                  else
                 mn=min(mn,grid[x1][y1]*findMin(x1,y1,grid));
                  
              }
                  
          }
          
          return dp2[i][j]=mn;
     }
};