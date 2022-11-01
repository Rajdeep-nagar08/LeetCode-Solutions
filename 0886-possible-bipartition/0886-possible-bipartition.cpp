class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>g[n];
        for(auto x:dislikes){
            g[x[0]-1].push_back(x[1]-1);  //0 to n-1
            g[x[1]-1].push_back(x[0]-1);
        }
       
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i]==-1){ 
            if(dfs(i,-1,0,g,vis)==false)
                    return false;
        }
        }
       return true;     
        
    }
    
    bool dfs(int source,int par,int color,vector<int>g[],vector<int>&vis){
        vis[source]=color;
        for(int x:g[source]){
            if(vis[x]==-1){
                if(dfs(x,source,!color,g,vis)==false)
                    return false;
            }
           else 
           {
               if(x!=par && vis[x]==color)
                  return false;
           }
     }
            return true;    
    }
};