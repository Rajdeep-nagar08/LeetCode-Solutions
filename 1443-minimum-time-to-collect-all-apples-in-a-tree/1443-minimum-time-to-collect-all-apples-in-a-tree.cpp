class Solution {
public:
    int minTime(int n, vector<vector<int>>& edg, vector<bool>& hasApple) {
        
        vector<int>g[n];
        
        vector<int>v(n,0);
        
        for(auto it:edg){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);

        }
        
          dfs(0,-1,g,hasApple,v);
        
        return v[0];
    }
    
    int dfs(int node,int par,vector<int>g[],vector<bool>&hasApple,vector<int>&v){
                
        for(int x:g[node]){
            if(x!=par){
                
                v[node]+=dfs(x,node,g,hasApple,v);
            }
        }
    
        
        if(hasApple[node]>0 || v[node]>0)
        return 2+v[node];
        
        return 0; 
    }
};