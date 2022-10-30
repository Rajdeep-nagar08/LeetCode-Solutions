int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
  
class Solution {
    
public:
    //int dx[4]={1,-1,0,0};
    //int dy[4]={0,0,1,-1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m=grid[0].size();
        bool vis[n+1][m+1][k+1];
        memset(vis,false,sizeof(vis));
        queue<array<int,4>>q;
        q.push({0,k,0,0});
        while(!q.empty()){
           auto [len,h,i,j]=q.front();
            q.pop();
            if(h<0)
                continue;
            vis[i][j][h]=true;
            if(i==n-1 && j==m-1)
                return len;
            for(int l=0;l<4;l++){
                int x1=i+dx[l];
                int y1=j+dy[l];
               if(x1>=0 && y1>=0 && x1<n && y1<m && vis[x1][y1][h]==false){
                  vis[x1][y1][h]=true;
                   
                 if(grid[x1][y1]==0){
                     
                     q.push({len+1,h,x1,y1});
                     }
                   else if(h>0){
                       
                   q.push({len+1,h-1,x1,y1});
                       }
               }
            }
            
        }
        return -1;
    }
};