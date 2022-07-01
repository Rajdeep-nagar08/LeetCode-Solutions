class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int>ans(k);
        
     // ans[i]= no of users whose total active minutes = i (1<=i<=k)
        
        // user => total active minutes
        
        unordered_map<int,unordered_set<int>>mp;
        
        for(auto it:logs){
            mp[it[0]].insert(it[1]);
        }
        
        for(auto it:mp){
          int actMin=it.second.size();
          ans[actMin-1]++;
        }
        
        return ans;
        
    }
};