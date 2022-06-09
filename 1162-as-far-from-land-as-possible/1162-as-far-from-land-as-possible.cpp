int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        
        int m=grid[0].size();
     
       /*
       
       start bfs from each 1 in all four directions and do dist++ , make visited 0 to 1 and push to queue
       
       let last 0 visited by any 1 at dist=3
       
       it means distance of this 0 from each 1 >=3
       
       Ans=3
       
       */
        int dist=0;
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==n*m || q.size()==0)
            return -1;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
         
        q.push({x,y});
        grid[x][y]=1;
                }
                                          
              }
            }
            
            dist++;
            
        }
    
        return dist-1;
        
        
    }
};