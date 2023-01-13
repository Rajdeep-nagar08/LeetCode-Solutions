class Solution {
public:
    
    int mx=-1;
    
    int longestPath(vector<int>& parent, string s) {
        
      int n=s.length();
        
      vector<int>g[n];
            
      for(int i=1;i<n;i++){
          g[i].push_back(parent[i]);
          g[parent[i]].push_back(i); 
      }
        
        dfs(0,-1,g,s);
        
        return mx;
        
    }
    
    
int dfs(int node,int par,vector<int>g[],string &s){
   
    int l1=1,l2=1;

        for(int x:g[node]){
            
            if(x!=par){
                
                int l=dfs(x,node,g,s);
                
                if(s[x]!=s[node]){
                    l++;
                    if(l1<l){
                        l2=l1;
                        l1=l;
                    }
                    else if(l2<l){
                        l2=l;
                    }
                }
            }
    }    
         
    mx=max({mx,l1+l2-1});
    
        return l1;
        
    }
};