int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};


class Solution {
public:
    int n,m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
     n=grid.size();
        
     m=grid[0].size();
        
        int mx=INT_MIN;
        
        
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                    if(grid[i][j]==1){
                    int count=0;
                dfs(i,j,grid,count);
                    }
            }
        }
        */
        
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                  
                  int count=0;
                  
                  dfs(i,j,grid,count);
                  
                  mx=max(mx,count);
              }
          }  
        }
        
        if(mx==INT_MIN)
        return 0;
        
        
        return mx;
        
    }
    
    
    void dfs(int i,int j,vector<vector<int>>&grid,int &count){
        count++;
        grid[i][j]=0;

        
        for(int j1=0;j1<4;j1++){
            int x1=i+dx[j1];
            int y1=j+dy[j1];
            if(x1<n && y1<m && x1>=0 && y1>=0 && (grid[x1][y1]==1)){
                dfs(x1,y1,grid,count);
            }
        }
    }
    
    
};