class Graph {
public:
    

    unordered_map<int,vector<pair<int,int>>>g1;
    
    Graph(int n, vector<vector<int>>& egs) {
        
        
        // make graph
        
        
        for(auto it:egs){
            g1[it[0]].push_back({it[1],it[2]});
        }
        
        
    }
    
    void addEdge(vector<int> eg) {
    
        
        // add edge
        
        
        g1[eg[0]].push_back({eg[1],eg[2]});
        
        
        
        ///
        
    }
    
    int shortestPath(int a, int b) {
        
        int ans=solveDist(a,b);
        
        
        if(ans>=INT_MAX)
            return -1;
        
        
        return ans;
    }
    
    int solveDist(int x,int y){
        
            
              
   set<pair<int,int>>st;
        
            st.insert({0,x});

   vector<int>dt(1004,INT_MAX);  
  
        
    dt[x]=0;    
        
        
      while(!st.empty()){
        
        auto x=*(st.begin());
        
                  int u=x.second;

        st.erase(x);
        
        
        for(auto it:g1[u]){
            
            
                        int wt=it.second; 

            int v=it.first;
            
            
            
            // 
            
            
            
            if(dt[v]>dt[u]+wt){ 
                st.erase({dt[v],v});
                
                
                
            dt[v]=dt[u]+wt; 
                
                
                st.insert({dt[v],v});
            }
            
            
        }
    }
        
        
        return dt[y];
       
    }
};
