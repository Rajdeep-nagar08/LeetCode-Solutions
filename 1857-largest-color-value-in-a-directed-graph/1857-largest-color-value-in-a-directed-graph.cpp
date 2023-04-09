int mx=1;
class Solution {
 vector<int>path;
    vector<int>vis;
 public:
    int largestPathValue(string col, vector<vector<int>>& edges) {
        int n=col.length();
        vector<int>g[n];
    vector<int>indeg(n,0);

        for(auto it: edges){
            g[it[0]].push_back(it[1]);
            indeg[it[1]]++;
             }
     
    /*
To get longest path, starts traversal from starting nodes (nodes having indeg==0) => knowns as topological sorting

    We can use BFS based Topological Sort to visit the nodes. When visiting the next node, we can forward the color information to the next node. Also Topo-sort can help detect circle.
    
    
        v[i][j] is the maximum count of j-th color from the ancester nodes to node i. 
            
      */
        
        vector<vector<int>>v(n, vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                v[i][col[i]-'a']++;
                q.push(i);
            }
        }
          
    int count=0;
    int ans=0;
      while(!q.empty()){
          int x=q.front();
          q.pop();
          count++;
          int mx=*max_element(v[x].begin(),v[x].end());
          ans=max(ans,mx);
    for(int y:g[x]){
              //update all colors for x->y
     for(int i=0;i<26;i++){
    v[y][i]=max(v[y][i],v[x][i]+(i==col[y]-'a'));
                }
                
        indeg[y]--;
        if(indeg[y]==0)
                q.push(y);
        }
  }
        
    if(count<n)
       return -1;
    
    return ans;
      
   }
                               
};