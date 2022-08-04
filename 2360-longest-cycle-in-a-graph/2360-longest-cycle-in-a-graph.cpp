class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        
        int n=edges.size();
        
        vector<int>g[n];
        
        
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
                g[i].push_back(edges[i]);
        }
        
        
         vector<bool>vis(n,false);
        
        
         bool iscycle=false;
        
         int ans=-1;
        
         vector<int>depth(n,0);

        
                        vector<int>path(n,0);


        for(int i=0;i<n;i++){
            
            if(vis[i]==false){
                
                int c=0;
                
                int d=0;
                

                if(dfs1(i,vis,path,g,c,d,depth)){
                  // return true;
                    ans=max(ans,c);
                    
                }
            }}
        
         //return false;
        
        return ans;

         }


          bool dfs1(int node,vector<bool>&vis,vector<int>&path,vector<int>g[],int&c,int &d,vector<int>&depth){
              
          vis[node]=true;
              
          d++;
              
          path[node]=1;
              
          depth[node]=d;
                            
          for( auto x:g[node]){
              
              if(vis[x]==false){
                  
                  if(dfs1(x,vis,path,g,c,d,depth)){
                     
                 //       c=max(c,depth[node]-depth[x]+1);
                      
                     path[x]=0;

                      return true;
                  }
              }
              
              
              else if(path[x]){
                   
                  c=max(c,depth[node]-depth[x]+1);
                  
                  path[x]=0;

                  return true;
              }
          }
              
          path[node]=0;
              
          return false;
              
      }
    

    };