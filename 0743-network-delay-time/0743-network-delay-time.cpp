class Solution {
public:

int networkDelayTime(vector<vector<int>>& time, int n, int k) {
        
  vector<pair<int,int>>g[n];

  for(auto it:time){
      g[it[0]-1].push_back({it[1]-1,it[2]});
  }

  vector<int>dist(n,INT_MAX);

  set<pair<int,int>>st;

  st.insert({0,k-1});

  dist[k-1]=0;


  while(st.size()>0){

      auto it1=*st.begin();

      st.erase(it1);

      int node=it1.second;

      int d=it1.first;

      for(auto it:g[node]){
          int d1=it.second;
          int node1=it.first;
          if(dist[node1]>d1+d){
              st.erase({dist[node1],node1});
              dist[node1]=d1+d;
              st.insert({dist[node1],node1});
          }
      }
  }

  int ans=0;

  for(int x:dist){
      if(x==INT_MAX)
      return -1;
      
      ans=max(ans,x);
  }

return ans;

    }
};