// using bottum up approach , generate a string corresponding to the respective subtree


class Solution {
public:
    
vector<int>ans;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edg, string labels) {
        
      
        vector<int>g[n];
        
        for(auto it:edg){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        
       vector<bool>vis(n,false);
        
        ans.resize(n,0);
        
        find(0,g,labels,vis);
        
        return ans;
        
    }
    
       vector<int> find(int node,vector<int>g[],string &lab,vector<bool>&vis){
           
           vis[node]=true;
           
           vector<int>v(26,0);
           
           for(int& x:g[node]){
               if(vis[x]==false){
              vector<int>v1=find(x,g,lab,vis); 
               
               for(int i=0;i<26;i++){
                   v[i]+=v1[i];
               }
              }
           }
           
           v[lab[node]-'a']++;
           
           ans[node]=v[lab[node]-'a'];
           
           return v;
       }
};