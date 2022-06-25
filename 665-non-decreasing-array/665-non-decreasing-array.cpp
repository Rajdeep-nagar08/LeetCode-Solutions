class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        // LIS >= n-1
        
        int n=nums.size();
        
        if(n==1)
            return true;
        
        vector<int>v;
        
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            
            int idx=upper_bound(v.begin(),v.end(),nums[i])-v.begin();
            
            if(idx>=0 && idx<v.size()){
                v[idx]=nums[i];
            }
            else
                v.push_back(nums[i]);
        }
        
        if(v.size()>=n-1)
            return true;
        
        return false;
    }
};