class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        
        int n=s1.size();
        
        unordered_map<int,vector<int>>g;
        
        for(int i=0;i<n;i++){
            int x=s1[i]-'a';
            int y=s2[i]-'a';
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        string ans;
                
        for(char ch:baseStr){
            
        vector<bool>vis(26,false);

            vis[ch-'a']=true;
            
            int small=ch-'a';
            
        dfs(ch-'a',small,vis,g);
            
            ans.push_back(small+'a');
        }
        return ans;
    }
    
    void dfs(int x,int &y,vector<bool>&vis,unordered_map<int,vector<int>>&g){
        
        for(int a:g[x]){
            if(vis[a]==false){
                vis[a]=true;
                y=min(y,a);
                dfs(a,y,vis,g);
            }
        }
    }
};