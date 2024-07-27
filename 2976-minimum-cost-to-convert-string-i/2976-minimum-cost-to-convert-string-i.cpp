#define lln long long int

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        
        
    vector<pair<int,int>>g[26];
        
     int n=original.size();

        
        for(int i=0;i<n;i++){
            g[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        
        
        
        unordered_map<int,vector<lln>>mp;  // src node ---> distance vector
        
        for(int s=0;s<n;s++){
              
          int src=original[s]-'a';
            
            
            if(mp.count(src)==1)
                continue;
            
        // Dijkstra
        
    vector<lln>dist(26,INT_MAX); 
        
   set<pair<lln,int>>st;
        
    dist[src]=0;    
        
    st.insert({0,src});
            
    while(!st.empty()){
        auto x=*(st.begin());
        st.erase(x);
        int u=x.second;
        for(auto it:g[u]){
            int v=it.first;
            lln wt=it.second;
            
            if(dist[v]>dist[u]+wt){ 
                st.erase({dist[v],v});
                dist[v]=dist[u]+wt;                                                               
                st.insert({dist[v],v});
            }
        }
    }
        
            
    mp[src]=dist;
        
}
    
    
        
        lln ans=0;
        
        
        for(int i=0;i<source.size();i++){
            
            
            if(source[i]==target[i])
                continue;
            
            int x=source[i]-'a';
            
            int y=target[i]-'a';
                                    
            if(mp.count(x)==0 or mp[x][y]==INT_MAX)
                return -1;
        
            
            ans+=mp[x][y];
            
        }

        
        
        return ans;
        
    }
};