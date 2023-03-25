#define lln long long int
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& e) {
        
        vector<int>g[n];
        
        for(auto it:e){
            g[it[0]].push_back(it[1]);
                        g[it[1]].push_back(it[0]);

        }
        
        vector<lln>v;
        
                    vector<bool>vis(n,false);

        for(int i=0;i<n;i++){
            if(vis[i]==false){
            lln count=0;
            dfs(i,vis,g,count);
            v.push_back(count);
            }
        }
        
        lln ans=0;
        
        sort(v.rbegin(),v.rend());
        
        int sz=v.size();
        
        vector<lln>pref(sz);
        
        pref[sz-1]=v[sz-1];
        
        for(int i=sz-2;i>=0;i--){
            pref[i]=pref[i+1]+v[i];
        }
        
        for(int i=0;i<sz-1;i++){
            lln a=pref[i+1];
            ans+=1ll*a*v[i];
        }
        
        return ans;
    }
    
     void dfs(int u,vector<bool>&vis,vector<int>g[],lln &count){
         
         vis[u]=true;
         count++;
         
         for(int v:g[u]){
             if(vis[v]==false){
                 dfs(v,vis,g,count);
             }
         }
         
     }
};