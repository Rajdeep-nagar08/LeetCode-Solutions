class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edg, int src,int dest) {
        
        vector<int>g[n];
        
        for(auto it:edg){
            g[it[0]].push_back(it[1]);
            
            g[it[1]].push_back(it[0]);

        }

       
        vector<bool>vis(n,false);
        
        vis[src]=true;
        
        dfs(src,g,vis);
        
        return vis[dest];
    }
    
    void dfs(int x,vector<int>g[],vector<bool>&vis){
        vis[x]=true;
        for(int y:g[x]){
            if(vis[y]==false)
            {
                vis[y]=true;
                dfs(y,g,vis);
            }
        }
    }
};