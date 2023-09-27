// minimum cost to move from [i,j] to [n-1, m-1]

// from each cell we have 4 choices => move to left, right, up down

class Solution {
public:
    int minCost(vector<vector<int>>& grid) { 
                
        int n=grid.size();
        
        int m=grid[0].size();

        deque<pair<int,pair<int,int>>>dq;  // {cost,i,j}
        
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        
        dq.push_front({0,{0,0}});
        
        while(!dq.empty()){
            
            int c=dq.front().first;
            
            int i=dq.front().second.first;
            
            int j=dq.front().second.second;
            
            dq.pop_front();
            
            if(i<0||j<0||i>=n||j>=m || vis[i][j]==true)
                continue;
            
            if(i==n-1 && j==m-1)
                return c;

            vis[i][j]=true;
            
    grid[i][j]==1?dq.push_front({c,{i,j+1}}):dq.push_back({c+1,{i,j+1}});
            
    grid[i][j]==2?dq.push_front({c,{i,j-1}}):dq.push_back({c+1,{i,j-1}});
            
    grid[i][j]==3?dq.push_front({c,{i+1,j}}):dq.push_back({c+1,{i+1,j}});
        
    grid[i][j]==4?dq.push_front({c,{i-1,j}}):dq.push_back({c+1,{i-1,j}});
            
        }
        
        return 0;
        
        }
};