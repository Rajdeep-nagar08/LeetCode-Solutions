class Solution {
public:
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
   int minimumObstacles(vector<vector<int>>& grid) {
        
  //     (i,j)=> m*i+j
           
        int n=grid.size();
        int m=grid[0].size();
       
       vector<pair<int,int>>g[n*m];
               
       int x1,y1;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
              for(int x=0;x<4;x++){
                  
                  x1=i+dx[x];
                  y1=j+dy[x];
                  
                  if(x1<n && y1<m && x1>=0 && y1>=0){
                      
              g[m*i+j].push_back({m*x1+y1,grid[x1][y1]});
                      
           //   cout<<m*i+j<<"->"<<m*x1+y1<<" "<<grid[x1][y1]<<endl;
                      
                  }
              }
            }
        }
          
    
  vector<int>dist(n*m,INT_MAX); 
       
   set<pair<int,int>>st;
    dist[0]=0;           
    st.insert({0,0});
       
     int u,v,wt;
       
    while(!st.empty()){
        
        auto x=*(st.begin());
        st.erase(x);
         u=x.second;
        
        for(auto &it:g[u]){
            
            v=it.first;
            wt=it.second; 
            
            if(dist[v]>dist[u]+wt){ 
                
                st.erase({dist[v],v});
                
                dist[v]=dist[u]+wt;                                                                        
				st.insert({dist[v],v});
            }
        }
    }
       
  return dist[n*m-1];

   }
};