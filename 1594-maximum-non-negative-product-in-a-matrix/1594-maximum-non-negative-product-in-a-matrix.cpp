/*
similar question: 

https://leetcode.com/problems/maximum-product-subarray/


TOP DOWN APPROACH


dp1[i][j]= max product from ([i,j] to [n-1][m-1]]

dp2[i][j]= min product from ([i,j] to [n-1][m-1]]


if(grid[0][0]>=0)
ans= grid[0][0]*dp1[0][0]

else if(grid[0][0]<0)
ans= grid[0][0]*dp2[0][0]




*/

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


/*


Bottom up approach
        
        dp1[i][j]= max +ve prouct from [0,0] to [i,j]
        
        dp[2][i][j]= min -ve product from [0,0] to [i,j]
        
        
        ans=dp[n-1][m-1]
        
        
#define lln long long int
int mod=1e9+7;

class Solution {
public:
    
    int maxProductPath(vector<vector<int>>& grid) {
        
       int n=grid.size();
        
       int m=grid[0].size();
        
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



*/


