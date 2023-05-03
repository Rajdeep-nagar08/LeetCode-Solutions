class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>mp1,mp2;
        
        for(int x:nums1){
            mp1[x]++;
        }
        
        for(int x:nums2){
         mp2[x]++;
        }
        
        vector<vector<int>>ans;
        
        vector<int>v1;
        for(auto it:mp1){
         if(mp2.count(it.first)!=1)
             v1.push_back(it.first);
        }
        
        vector<int>v2;
        for(auto it:mp2){
         if(mp1.count(it.first)!=1)
             v2.push_back(it.first);
        }
        
        ans.push_back(v1);
                ans.push_back(v2);
        
        return ans;

    }
};