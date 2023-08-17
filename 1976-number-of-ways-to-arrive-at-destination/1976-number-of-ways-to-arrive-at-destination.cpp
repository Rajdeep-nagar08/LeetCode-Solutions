#define lln long long int

class Solution {
public:
 int mod = (int)(1e9 + 7);
    
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int,int>>adj[n];
        
        for( auto it :roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
     
    priority_queue<pair<lln,lln>,vector<pair<lln,lln>>,greater<pair<lln,lln>>>pq;
        
        vector<lln>dis(n,1e15);
        vector<lln>ways(n,0);
        
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        
        while(!pq.empty())
        {
            auto it=pq.top();
            lln node=it.second;
            lln dist=it.first;
            pq.pop();
            // cout<<node<<endl;
            for(auto a:adj[node])
            {
                
                
                lln adjnode=a.first;
                lln cost=a.second;
                // cout<<adjnode<<endl;
                if(dis[adjnode]>dist+cost)
                {
                    // cout<<adjnode<<endl;
                    dis[adjnode]=dist+cost;
                    ways[adjnode]=ways[node];
                    pq.push({dis[adjnode],adjnode});
                }
                
                else if(dis[adjnode]==dist+cost)
                {
                    // dis[a.first]=dist+a.second;
                    ways[adjnode]=(ways[node]+ways[adjnode])%mod;
                }
                
            }
            
        }
        
        return ways[n-1]%mod;
    
        
    }
};