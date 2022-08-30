class Solution
{
public:
    bool cycle(vector<vector<int>> &adj, int s, vector<bool> &vis, vector<bool> &recvis)
    {
        vis[s] = true;
        recvis[s] = true;
        for (auto x : adj[s])
        {
            if (!vis[x])
            {
                if (cycle(adj, x, vis, recvis))
                {
                    return true;
                }
            }
            else if (vis[x] and recvis[x])
                return true;
        }
        
        recvis[s] = false;
        return false;
        
    }
    
    
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int s, vector<int> &ans)
    {

        vis[s] = true;
        
        for (auto x : adj[s])
        {
            if (!vis[x])
            {
                if (ans[x])
                    return true;
                else
                {
                    if (dfs(adj, vis, x, ans))
                        return true;
                }
            }
            else
                return true;
        }
        
        return false;
    }
    
    

    vector<int> eventualSafeNodes(vector<vector<int>> &adj)
    {
        int n = adj.size();
        
        vector<int> ans(n, 0),ans1(n,0);
        
        vector<bool>vis1(n,false),vis2(n,false);
        
        vector<bool>recvis(n,false);
        
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0)

                ans[i]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 1)
                continue;
            else if (dfs(adj, vis1, i, ans) and !cycle(adj, i, vis2, recvis))
                ans1[i]++;
        }
       
        vector<int> res;
        
        for (int i = 0; i < n; i++)
        {
            if (ans[i]==1 || ans1[i]==1)
                res.push_back(i);
        }
        
        return res;
        
    }
};