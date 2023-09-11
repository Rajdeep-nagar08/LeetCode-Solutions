class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupsz) {
        
        unordered_map<int,vector<vector<int>>>mp;
        
        int n=groupsz.size();
        
        for(int i=0;i<n;i++){
            if(mp.count(groupsz[i])==1){
                int sz=mp[groupsz[i]].size();
                vector<int>v1=mp[groupsz[i]][sz-1];
                if((int)v1.size()==groupsz[i]){
                    mp[groupsz[i]].push_back({i});
                }
                else{
                    mp[groupsz[i]][sz-1].push_back(i);
                }
            }
            else{
                mp[groupsz[i]].push_back({i});
            }
        }
        
        
        vector<vector<int>>ans;
        
        for(auto it:mp){
            for(auto v1:it.second){
                ans.push_back(v1);
                }   
        }
        
        return ans;
    }
};