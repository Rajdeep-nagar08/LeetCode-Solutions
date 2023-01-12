class Solution {
public:
    
    vector<int>ans;
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edg, string lab) {
        
ans.resize(n,0);
        
        vector<int>g[n];
        
        for(auto it:edg){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
       
             
       dfs(0,-1,g,lab); 
        

        return ans;
        
    }
    
    
    unordered_map<char,int> dfs(int node,int par,vector<int>g[],string &lab){
      
   unordered_map<char,int>mp;        

        for(int x:g[node]){
            if(x!=par){
              unordered_map<char,int>mp1=dfs(x,node,g,lab);  
              for(auto it:mp1){
                  mp[it.first]+=it.second;
              }
            }
        }
        
 mp[lab[node]]++;
        
        ans[node]=mp[lab[node]];
        
        return mp;
        
    }
};