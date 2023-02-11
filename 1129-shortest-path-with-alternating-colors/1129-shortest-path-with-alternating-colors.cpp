class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        vector<pair<int,int>>g[n];
        for(auto x:red_edges)
            g[x[0]].push_back({x[1],0});
        for(auto y:blue_edges)
            g[y[0]].push_back({y[1],1});
        
        queue<pair<int,int>>q;
        vector<int>dist(n,-1);
        vector<vector<bool>>vis(n,vector<bool>(2,false));
        q.push({0,-1});
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            if(dist[node]==-1)
             dist[node]=d;
             for(auto x:g[node]){
                if(x.second!=color && vis[x.first][x.second]==false){
                    vis[x.first][x.second]=true;
                    q.push({x.first,x.second});
                }
            }
        }
            d++;
        }
        return dist;
    }   
};