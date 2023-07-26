class Solution {
public:
    int n;
    
    
    int ans=-1;
    
    
    int longestPath(vector<int>& par, string s) {
        
        
        
        n=par.size();
        
        
        vector<int>g[n];
        
        for(int i=0;i<n;i++){
            if(par[i]!=-1){
                g[par[i]].push_back(i);
            }
        }
        
        
         dfs(0,-1,g,s);
        
        return ans;
    }
    
    int dfs(int node,int par,vector<int>g[],string &s){
        
        int maxLen1=1, maxLen2=1;
        
        for(int y:g[node]){
            
            if(y!=par){
                
                int validLen=dfs(y,node,g,s);
                
                if(s[node]!=s[y]){   // returning from root
                    
                    validLen++;
                    
                    if(maxLen1<validLen){
                        maxLen2=maxLen1;

                        maxLen1=validLen;
                    }
                    else{
                        maxLen2=max(maxLen2,validLen);
                    }
                    
                }
            }
        }
        
        
        ans=max(ans,maxLen1+maxLen2-1);

        return maxLen1;
        
        
    }
};