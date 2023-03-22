class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>>g[n];
        
        
        for(auto it:roads){
            g[it[0]-1].push_back({it[1]-1,it[2]});
            g[it[1]-1].push_back({it[0]-1,it[2]});
        }
        
    vector<int>dist(n,INT_MAX);   
        
   set<pair<int,int>>st;
        
    dist[0]=INT_MAX;   
        
    st.insert({INT_MAX,0});
        
    while(!st.empty()){
        auto x=*(st.begin());
        st.erase(x);
        int u=x.second;
        for(auto it:g[u]){
            int v=it.first;
            int wt=it.second; 
            if(dist[v]>min(dist[u],wt)){ 
                st.erase({dist[v],v});
            dist[v]=min(dist[u],wt);                                                                         
                st.insert({dist[v],v});
            }
        }
    }
       
        if(dist[n-1]==INT_MAX)
            return -1;
        
   return dist[n-1]; 
        
    }
};