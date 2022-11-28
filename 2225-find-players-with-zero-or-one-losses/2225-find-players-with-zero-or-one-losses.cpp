class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        
        vector<vector<int>>ans;
        
        unordered_map<int,int>win,los;
        
        for(auto it:m){
            win[it[0]]++;
            los[it[1]]++;
        }
        
        vector<int>w,l;
        
        for(auto it:win){
            if(los.count(it.first)!=1)
                w.push_back(it.first);
        }
        
        
        for(auto it:los){
            if(los[it.first]==1)
                l.push_back(it.first);
        }
        
        sort(w.begin(),w.end());
        sort(l.begin(),l.end());

        ans.push_back(w);
        ans.push_back(l);
        
        return ans;
        
    }
};