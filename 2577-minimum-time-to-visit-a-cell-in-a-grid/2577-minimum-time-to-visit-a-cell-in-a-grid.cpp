/*

minimum tum to reach [n-1, m-1]

dp[i][j]= minimum time to reach i,j from [0,0]

no, dp will not work here, bcs cycle can form

use BFS or dijkstra

*/

class Solution {
public:
    int n, m;
    
    int dx[4]={1,-1,0,0};
    
    int dy[4]={0,0,1,-1};
    
    int minimumTime(vector<vector<int>>& grid) {
     
        n=grid.size();
        
        m=grid[0].size();
     
        
        // base case
        
        if(grid[0][1]>1 && grid[1][0]>1)
            return -1;
    
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        vector<vector<int>>time(n, vector<int>(m, 1e9));
        
        // timer[i][j]= minimum time to reach from [0,0] to [i, j]
        
        pq.push({0,0,0});
        
        while(!pq.empty()){
            
            auto it=pq.top();
            
            pq.pop();
            
            int t=it[0];
            
            int i1=it[1];
            
            int j1=it[2];
                        
            for(int x=0;x<4;x++){
                int i2=i1+dx[x];
                int j2=j1+dy[x];
                if(i2<n && i2>=0 && j2<m && j2>=0){
                    
                    int t1;
                    
                    if(t+1>=grid[i2][j2]){ 
                        
                         t1=t+1;
                      
                    }else{
                     // move back and froth
                        
                        t1=grid[i2][j2];
                        
                       int diff=grid[i2][j2]-t;
                        
                       if(diff%2==0)
                           t1++;
                        
                        
                    }
                    
                    
                    if(t1<time[i2][j2]){
                        time[i2][j2]=t1;
                        pq.push({t1, i2, j2});
                    }
                    
                }
            }
            
        }
           
        
        if(time[n-1][m-1]==1e9)
            return -1;
        
        return time[n-1][m-1];
        
    }
};