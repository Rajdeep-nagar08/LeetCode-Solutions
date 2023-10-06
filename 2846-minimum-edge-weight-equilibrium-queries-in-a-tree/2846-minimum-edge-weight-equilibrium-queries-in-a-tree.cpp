/*


1 <= wi <= 26

first we make any node as root node

then we store frequency of each wight from root node to node x in freq[x][wt]


for path from a to b

first we find lca(a,b)

then we can check frequency of each weight between lca -----a  and lca ------b 

optimally using freq as - 

The frequency of edge weight w on the path from a to b is equal to freq[a][w] + freq[b][w] - freq[lca(a,b)][w] * 2

*/

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& qr) {
        
        
        vector<pair<int,int>>g[n];
                
        for(auto it:edges){

            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});

        }
        
        
        // root = 0, STORING WEIGHT FREQUENCY PROCESSING
        
        vector<vector<int>>freq(n,vector<int>(27,0));
        
        queue<int>q;
        
        q.push(0);
        
        vector<bool>vis(n,false);
        
        vis[0]=true;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                for(auto y:g[x]){
                    if(vis[y.first]==false){
                        vis[y.first]=true;
                        for(int w=1;w<=26;w++)
                        freq[y.first][w]=freq[x][w];
                        
                        freq[y.first][y.second]++;
                        
                        q.push(y.first);
                    }
                }
            }
        }
            
        
        // LCA PROCESSING
        
    int ht = (int)ceil(log2(n));
        
   vector<vector<int>>dp(n, vector<int>(ht + 1, -1));
        
   vector<int> height(n);
        
        
    dfs(0, 0, dp, height, ht, g);   // root = 0
                
    int m=qr.size();
        
    vector<int>ans(m);
        

   
    for(int i=0;i<m;i++){
        int u=qr[i][0];
        
        int v=qr[i][1];
        
        int lc_a = lca(u,v,ht,height, dp);
            
        int mn=1e5;
        
        
        for(int w=1;w<=26;w++){
            int edgeCount=height[u]-height[lc_a] + height[v]-height[lc_a];
            int whtFreq=freq[u][w]+freq[v][w]-freq[lc_a][w]*2;

            mn=min(mn,edgeCount-whtFreq);
        }
        
        ans[i]=mn;
    }
        
    
        return ans;
        
    }
    
    
void dfs(int u, int p, vector<vector<int>>&dp, vector<int> &height, int ht, vector<pair<int,int>>g[])
{

    dp[u][0] = p;
    for (int i = 1; i <= ht; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];

    for (auto v : g[u])
    {
        if (v.first != p)
        {
            height[v.first] = height[u] + 1;
            dfs(v.first, u, dp, height, ht, g);
        }
    }
}

    
    
int lca(int u, int v, int ht, vector<int> &height, vector<vector<int>>&dp)
{

    if (height[u] < height[v])
        swap(u, v);

    for (int i = ht; i >= 0; i--)
        if ((height[u] - pow(2, i)) >= height[v])
            u = dp[u][i];
    if (u == v)
        return u;

    for (int i = ht; i >= 0; i--)
    {
        if (dp[u][i] != dp[v][i])
        {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}

};