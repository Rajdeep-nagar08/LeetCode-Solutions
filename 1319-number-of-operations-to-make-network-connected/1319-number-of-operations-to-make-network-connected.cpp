class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>g[n];
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
 }
        
        
        vector<bool>vis(n,false);
        int comp=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                comp++;
                dfs(i,vis,g);
            }
        }
        if(comp==0)
            return 0;
        if(n>connections.size()+1)
            return -1;
        return comp-1;
        
    }
    void dfs(int node,vector<bool>&vis,vector<int>g[]){
        vis[node]=true;
        for(int x:g[node]){
            if(vis[x]==false)
                dfs(x,vis,g);
        }
    }
};