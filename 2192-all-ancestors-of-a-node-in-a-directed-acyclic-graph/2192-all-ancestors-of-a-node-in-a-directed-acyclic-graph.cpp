class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        
        vector<int>g[n];
        
        for(auto it:e){
            g[it[0]].push_back(it[1]);
        }
        
        vector<vector<int>>ans(n);
        
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,g,vis,ans);
        }
        
        return ans;
    }
    
      void dfs(int t,int node,vector<int>g[],vector<int>&vis,vector<vector<int>>&ans){
          vis[node]=1;
          
          for(int x:g[node]){
              if(vis[x]==0){
                  ans[x].push_back(t);
                  dfs(t,x,g,vis,ans);
              }
          }
      }
};