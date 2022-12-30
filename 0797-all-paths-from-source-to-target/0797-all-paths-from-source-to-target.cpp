class Solution {
public:
            vector<vector<int>>ans;

            vector<int>temp;

    int n;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        n=graph.size();
        
        vector<int>g[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                g[i].push_back(graph[i][j]);
            }
        }
        
        
        
        vector<bool>vis(n,false);

        vis[0]=true;
        
        temp.push_back(0);
        
        dfs(0,g,vis);
        
        return ans;
    }
    
    void dfs(int i,vector<int>g[],vector<bool>&vis){
        
        if(i==n-1){
            ans.push_back(temp);
            return;
        }
        
        for(int x:g[i]){
            if(vis[x]==false){
                vis[x]=true;
                temp.push_back(x);
                dfs(x,g,vis);
                temp.pop_back();
                vis[x]=false;
            }
        }
    }
};