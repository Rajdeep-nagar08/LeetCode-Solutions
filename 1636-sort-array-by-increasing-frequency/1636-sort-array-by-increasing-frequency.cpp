class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        
        int n=nums.size();
        
        
        unordered_map<int,int>mp;
        
        for(int x:nums){
            mp[x]++;
        }
        
        vector<pair<int,int>>v;
        
        for(auto it:mp){
            v.push_back({it.second,it.first});  // freq ,no
        }
        
         sort(v.begin(),v.end(),[](pair<int,int>&p1,pair<int,int>&p2){
             if(p1.first<p2.first)
                 return true;
                
              if(p1.first==p2.first)
             return p1.second>=p2.second;
             
             return false;
         });
        
        vector<int>ans;
        
        for(auto it:v){
            int need=it.first;  // freq
            int no=it.second;  // no
            for(int i=0;i<need;i++)
            ans.push_back(no);
        }
        
        return ans;
    }
};