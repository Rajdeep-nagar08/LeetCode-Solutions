class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
      
        
        /*
        
        a+b == d-c
        
        
        */
        
        
        unordered_map<int,vector<int>>mp;
        
        
        int n=nums.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[j]-nums[i]].push_back(i);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int idx:mp[nums[i]+nums[j]]){
                    if(idx>j)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};