class Solution {
public:
    
    vector<int>dist;
    
    vector<int>cnt;
    
    vector<int>ans;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        
        vector<int>g[n];
        
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        dist.resize(n,0);
        
        cnt.resize(n,0);
        
        ans.resize(n,0);
        
        
        dfs1(0,-1,g);
        
//         for(int x:dist){
//             cout<<x<<" ";
//         }
        
        dfs2(0,-1,g);
        
        return ans;
        
        
        
        
    }
    
    int dfs1(int node, int par, vector<int>g[]){
        
        int c;
        
        for(int x:g[node]){
           if(x!=par){
               c=1+dfs1(x,node,g);
               cnt[node]+=c;
               dist[node]+=c+dist[x];
               
           } 
        }
    
        return cnt[node];
    }
    
    
    void dfs2(int node, int par,vector<int>g[]){
        
    // answer from up = total ans of parent node - contribution from this node subtree + (no of nodes from upper side)
        
    // answer from up = ans[par] - contribution from this node subtree + (cnt[0]-cnt[node])
        
   // contribution from this node subtree = dist[node]+cnt[node]+1
        
  // answer from up = ans[par] - (dist[node]+cnt[node]+1) + (cnt[0]-cnt[node])
        
        
        int ansUp= 0;
        
        if(par!=-1){
            ansUp+=ans[par]-(dist[node]+cnt[node]+1)+ (cnt[0]-cnt[node]);
        }
        
        ans[node]=ansUp+dist[node];
            
        for(int x:g[node]){
            
            if(x!=par){
                
               dfs2(x,node,g); 
                
            }
        }
        
    }
};