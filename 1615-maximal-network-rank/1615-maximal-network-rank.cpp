// there is a road between i---j, now find no of rods connected to them 
          
          //no of roads connected to i=> size of g[i] similarly no of roads connected to j=> size of g[j] and one rod is common in them
          

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
      vector<int>g[n];
      
      for(auto it:roads){
        g[it[0]].push_back(it[1]);
       g[it[1]].push_back(it[0]);

      }
      
      int ans=0;
      
      for(int i=0;i<n;i++){
         int count=0;
        for(int j=0;j<n;j++){
          
          if(i==j)
            continue;
          
          count=(int)g[i].size() + (int)g[j].size();
          
          for(int x:g[i]){
            if(x==j){ //both are also directly connected
              count--;
              break;
            }
          }
        ans=max(ans,count);

        }
      }
      
      return ans;
    }
};