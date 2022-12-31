int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int sx,sy,empty=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                if(grid[i][j]!=-1)
                    empty++;
            }
        }
        
        return dfs(sx,sy,1,empty,grid);
    }
    
       int dfs(int x,int y,int steps,int empty,vector<vector<int>>grid){
          
           if(grid[x][y]==2){
               if(steps==empty)
                   return 1;
               else
                   return 0;
           }
           
          grid[x][y]=-1;
          
         int ans=0;
         for(int i=0;i<4;i++){
           int x1=x+dx[i];
           int y1=y+dy[i];
           if(x1<0 || y1<0 || x1>=grid.size() || y1>=grid[0].size()|| grid[x1][y1]==-1)
               continue;
            ans+=dfs(x1,y1,steps+1,empty,grid);
         }
         
           grid[x][y]=0;
           
           return ans;
       }
};      
    
    
    
    
          