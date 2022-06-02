class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
         
        /*
        
        ans[x]=y , if y is the person with smallest quiteness and money >= x
        
        */
        
        int n=q.size();
        
        vector<int>g[n];
        
        for(auto it:r){
            g[it[1]].push_back(it[0]);
        }
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            vis[i]=true;
            int node=i;
            int mn=q[i];
            
            dfs(i,vis,q,g,node,mn);
            
            ans[i]=node;
        }
        
        return ans;
        
    }
    
void dfs(int i,vector<bool>&vis,vector<int>&q,vector<int>g[],int & node,int &mn){
    
        for(auto j:g[i]){
            if(vis[j]==false){
                vis[j]=true;
                if(mn>q[j]){
                    mn=q[j];
                    node=j;
                }
                dfs(j,vis,q,g,node,mn);
            }
        }
    }
};