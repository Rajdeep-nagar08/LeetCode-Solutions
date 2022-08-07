int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    int n;
    
    int m;
    
    int numEnclaves(vector<vector<int>>& grid) {
      
        
n=grid.size();
    
m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
        
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs2(i,j,grid,count);
                }
            }
        }
        
        
        return count;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        
        grid[i][j]=-1;
        
        for(int i1=0;i1<4;i1++){
            int x1=i+dx[i1];
            
            int y1=j+dy[i1];
            
            if(x1<n && y1<m && x1>=0 && y1>=0 && (grid[x1][y1]==1)){
                dfs(x1,y1,grid);
            }
        }
    }
    
    
    void dfs2(int i,int j,vector<vector<int>>& grid,int &count){
        
        grid[i][j]=-2;
        
        count++;
        
        for(int i1=0;i1<4;i1++){
            
            int x1=i+dx[i1];
            
            int y1=j+dy[i1];
            
            if(x1<n && y1<m && x1>=0 && y1>=0 && (grid[x1][y1]==1)){
                dfs2(x1,y1,grid,count);
            }
        }
    }
};