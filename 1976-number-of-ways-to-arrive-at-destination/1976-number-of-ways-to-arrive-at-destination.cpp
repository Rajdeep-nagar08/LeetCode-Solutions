// #define lln long long int

// class Solution {
// public:
//  int mod = (int)(1e9 + 7);
    
//     int countPaths(int n, vector<vector<int>>& roads) 
//     {
//         vector<pair<int,int>>adj[n];
        
//         for( auto it :roads)
//         {
//             adj[it[0]].push_back({it[1],it[2]});
//             adj[it[1]].push_back({it[0],it[2]});
//         }
        
     
//     priority_queue<pair<lln,lln>,vector<pair<lln,lln>>,greater<pair<lln,lln>>>pq;
        
//         vector<lln>dis(n,1e15);
//         vector<lln>ways(n,0);
        
//         dis[0]=0;
//         ways[0]=1;
//         pq.push({0,0});
        
        
//         while(!pq.empty())
//         {
//             auto it=pq.top();
//             lln node=it.second;
//             lln dist=it.first;
//             pq.pop();
//             // cout<<node<<endl;
//             for(auto a:adj[node])
//             {
                
                
//                 lln adjnode=a.first;
//                 lln cost=a.second;
//                 // cout<<adjnode<<endl;
//                 if(dis[adjnode]>dist+cost)
//                 {
//                     // cout<<adjnode<<endl;
//                     dis[adjnode]=dist+cost;
//                     ways[adjnode]=ways[node];
//                     pq.push({dis[adjnode],adjnode});
//                 }
                
//                 else if(dis[adjnode]==dist+cost)
//                 {
//                     // dis[a.first]=dist+a.second;
//                     ways[adjnode]=(ways[node]+ways[adjnode])%mod;
//                 }
                
//             }
            
//         }
        
//         return ways[n-1]%mod;
    
        
//     }
// };


int mod=1e9+7;
#define lln long long int
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        if(n==2)
            return 1;
        vector<pair<int,int>>g[n];
        for(auto x:roads){
            g[x[0]].push_back({x[1],x[2]});
           g[x[1]].push_back({x[0],x[2]});
        }
           vector<lln>dist(n,1e15+1);
           vector<lln>ways(n,0);    //no of ways to reach a node by shortest path
           set<pair<lln,lln>>st;

            dist[0]=0;
            ways[0]=1;           //one way to reach source node
            st.insert({0,0});
            while(!st.empty()){
                auto x=*(st.begin());
                st.erase(x);
                int u=x.second;
                lln w=x.first;
                for(auto it:g[u]){
                    int v=it.first;
                    lln wt=it.second; 
                    if(dist[v]>w+wt){       
                       st.erase({dist[v],v});
                        dist[v]=w+wt;  
                        
//as previous shortest path of v from source is
                                                
//  greater in compare to path through u
                        
                        ways[v]=ways[u];        
// to go from source to v (source->v) we must                                                     follow path from source->u,so no of ways to                                                    reach v=no of ways to reach u via shortest path                                                    
                        st.insert({dist[v],v});
                    }
                    else if(dist[v]==dist[u]+wt)      
//as previous shortest path of v from                                                              source is equal to shortest path of v                                                             from source-u-v, so we can go upto v                                                             either through all previous paths                                                                    ways[v] and also via u ways[u]
                        ways[v]=(ways[v]+ways[u])%mod;
                }
            }
         return ways[n-1];   
    }
};