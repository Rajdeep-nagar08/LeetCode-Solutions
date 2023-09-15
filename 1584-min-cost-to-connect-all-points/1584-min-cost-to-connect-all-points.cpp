class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
      
       vector<vector<pair<int,int>>>g(n);
      
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          int u=i;
          int v=j;
          int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
          g[u].push_back({v,d});
          g[v].push_back({u,d});
        }
      }
      
     vector<int>dist(n,INT_MAX);
     vector<bool>vis(n,false);
    dist[0]=0;
    set<pair<int,int>>st;
    st.insert({0,0});
    int sum=0;
    while(!st.empty()){
      auto x=*(st.begin());
      st.erase(x);
      vis[x.second]=true;
      sum=sum+x.first;
      for(auto it:g[x.second]){
        if(vis[it.first])
          continue;
      if(dist[it.first]>it.second){
          st.erase({dist[it.first],it.first});
        dist[it.first]=it.second;
          st.insert({dist[it.first],it.first});
        }
      }
    }
    return sum;
  }
  
};