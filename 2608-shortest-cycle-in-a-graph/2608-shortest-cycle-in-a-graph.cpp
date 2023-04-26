class Solution {
public:
    
    int l;
    
    int findShortestCycle(int n, vector<vector<int>>& edg) {
        
        vector<int>g[n];
        
        for(auto it:edg){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
     
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            queue<pair<int,int>>q;
            
            vector<bool>vis(n,false);
            
            vector<int>ht(n);
            
            q.push({i,-1});
            
            ht[i]=0;
            
            vis[i]=true;
            
            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    int node=q.front().first;
                    int par=q.front().second;
                    q.pop();
                    for(int x:g[node]){
                        if(vis[x]){
                            if(x!=par)
                          ans=min(ans,ht[node]+ht[x]+1);  
                        }
                        else{
                            vis[x]=true;
                            ht[x]=ht[node]+1;
                            q.push({x,node});
                        }
                    }
                }
            }
        }
        
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    
 
    
};