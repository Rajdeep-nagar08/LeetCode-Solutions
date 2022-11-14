/*
if two stones are in same row or in same column than remove one of them

Highest no of stones that can be removed=?

make a graph btw the points that share any row or column

Now for any connected components , if there is only 1 node than no needs to do anything , otherwise if no of nodes in connected comp.= n than remove any n-1
nodes from that ,only left one node in it

*/

class Solution {
public:
    int removeStones(vector<vector<int>>& st) {
       
      int n=st.size();
      
      vector<int>g[n];
      
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if((st[i][0]==st[j][0]) || (st[i][1]==st[j][1])){
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
      
      vector<bool>vis(n,false);
      int ans=0;
      for(int i=0;i<n;i++){
        int count=0;
        if(vis[i]==false){
          dfs(i,g,vis,count);
        ans=ans+(count-1);
        }
      }
      
      return ans;
    }
  
     void dfs(int node,vector<int>g[],vector<bool>&vis,int &count){
       vis[node]=true;
       
       count++;
       
       for(int x:g[node]){
         if(vis[x]==false)
           dfs(x,g,vis,count);
       }
     }
};