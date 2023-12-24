class Solution {
public:
    int dfs(int i, int j,vector<vector<int>> &grid,int n,int m){
        if(i>=n) return j;
        if(grid[i][j]== 1 and j+1< m and grid[i][j+1]== 1) 
            return dfs(i+1,j+1,grid,n,m);
        
        else if(grid[i][j]==-1 and j-1>=0 and grid[i][j-1]==-1) 
            return dfs(i+1,j-1,grid,n,m);
        
        else if(grid[i][j]==1 and j+1>=m) 
            return -1;

        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> col(m);
        for(int i=0;i<m;i++){
            col[i]=dfs(0,i,grid,n,m);
        }
        return col;                                                                                
    }
};