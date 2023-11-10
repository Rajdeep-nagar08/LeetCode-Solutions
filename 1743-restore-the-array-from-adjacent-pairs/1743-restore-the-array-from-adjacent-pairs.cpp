class Solution {
vector<int>ans;
    unordered_set<int>vis;
    unordered_map<int, vector<int>>mp;
public:
    vector<int> restoreArray(vector<vector<int>>& v) {
        int start;
    
        for(auto it:v){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
            
        }
        
        for(auto it:mp){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }
        
        dfs(start);
        
        return ans;
        
        
    }
    
    void dfs(int start){
        
        vis.insert(start);
        ans.push_back(start);
        
        for(auto it:mp[start]){
            if(vis.count(it)!=1)
                dfs(it);
        }
    }
};
            
