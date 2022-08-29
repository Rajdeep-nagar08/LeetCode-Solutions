int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    
    int n,m;

    int numIslands(vector<vector<char>>& grid) {
      
        
        n=grid.size();
        
        m=grid[0].size();
        
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                      count++;
                }
            }
        }
        
        
        return count;
        
        
    }
    
    void dfs(int x,int y,vector<vector<char>>&grid){
                
        grid[x][y]='2';
        
        for(int i=0;i<4;i++){
            
            int x1=x+dx[i];
            
            int y1=y+dy[i];
            
    if(x1<n && y1<m && x1>=0 && y1>=0 && (grid[x1][y1]=='1'))
                dfs(x1,y1,grid);
        }
    }
};