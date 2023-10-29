// unordered_map<int,unordered_map<int,int>>dp;

/*

at each node, we have two choices, either collect coins by 1st way or second way


NOTE: if we apply 2nd way to more than 13 ancestor nodes, then all the coins to their childs will become zero, as max coins can be upto 10000


*/

int dp[100001][15];

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
               
        memset(dp,-1,sizeof(dp));
        
        int n=coins.size();
        
        vector<int>g[n];
        
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        
        int half=0; 
        
        return max(coins[0]-k+dfs(0,-1,half,g,k,coins),coins[0]/2+dfs(0,-1,half+1,g,k,coins));
    }
    
    
    int dfs(int node, int par, int half, vector<int>g[], int k, vector<int>&coins){
        
        int ans=0;
        
        if(dp[node][half]!=-1)
            return dp[node][half];
        
        for(int y:g[node]){
            if(y!=par){
            int points= coins[y]/(pow(2,half));
                
            if(half==14){
            
             return 0;
                
            }
                
                else{
                    
                                
       ans+= max(points-k+dfs(y,node,half,g,k, coins),(points/2)+dfs(y,node,half+1,g,k, coins));

                    
                }
            }
            
        }
        
        return dp[node][half]=ans;
    }
};