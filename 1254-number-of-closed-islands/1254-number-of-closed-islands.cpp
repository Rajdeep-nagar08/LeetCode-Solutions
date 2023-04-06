int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
      //  vector<vector<bool>>vis(n,vector<bool>(m,false));
      
        int count=0;
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0 )
                    dfs(i,j,grid);
                }}
    
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid);
                }}}
      return count;  
    }
    
   void dfs(int x,int y,vector<vector<int>>&grid) {
   grid[x][y]=1;
   
   for(int i=0;i<4;i++){
       int p=x+dx[i];
       int q=y+dy[i];
   if(isvalid(p,q,grid))
       dfs(p,q,grid);
   }
   }
    
    bool isvalid(int x,int y,vector<vector<int>>&grid){
        if( x>=0 && x<=n-1 && y>=0 && y<=m-1 && grid[x][y]==0)
            return true;
        return false;

    }
};