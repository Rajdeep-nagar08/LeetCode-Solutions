/*
min changes in edges so that each node can visit 0

// start traversal from 0 , if there is True edge from 0=> other node, count++ becouse we need all edges towards 0
*/


class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        
      vector<int>g[n];
      
      vector<int>g1[n];
      
      for(auto it:c){
        //true edges
        g[it[0]].push_back(it[1]);
        
        // fake edges , used to traverse graph from 0 to outward
        g1[it[0]].push_back(it[1]);
        g1[it[1]].push_back(it[0]);
      
      }
      
      
      
      queue<int>q;
      q.push(0);
      int ans=0;
      vector<bool>vis(n,false);
      int count=0;
      
      while(!q.empty()){
        int sz=q.size();
        
        while(sz--){
          int x=q.front();
          q.pop();
          vis[x]=true;
        
          //movin from 0 to other nodes (x=>y)
          for(int y:g1[x]){
            if(vis[y]==false){
              //if there is true node from x=>y , count++ becous we need all edges from y=>x
              for(int a:g[x]){
                if(a==y){
                  count++;
                  break;
                }
              }
               q.push(y);
            }
          }
          
        }
      }
      
      return count;
    }
};