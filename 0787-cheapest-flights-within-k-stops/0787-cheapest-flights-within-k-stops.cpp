class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
       vector<vector<pair<int,int>>>g(n);
        
        for(auto it:f){
            g[it[0]].push_back({it[1],it[2]});
        }
         
      set<vector<int>>st;
        st.insert({0,src,0});//dist,node,stop
        
        while(!st.empty()){
            vector<int>v=*st.begin();
            st.erase(v);
            
            int d=v[0];
            int node=v[1];
            int stop=v[2];
            if(node==dst)
                return d;
            if(stop>k)
                continue;
            
            for(auto it:g[node]){
                st.insert({d+it.second,it.first,stop+1});
            }
        }
        
        return -1;     
    }
};