class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        vector<int>ans;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(ans.size()==0 || nums[i]>ans[ans.size()-1])
                ans.push_back(nums[i]);
            
            auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
            
            *it=nums[i];
        }
        
        return ans.size();
        
    }
};