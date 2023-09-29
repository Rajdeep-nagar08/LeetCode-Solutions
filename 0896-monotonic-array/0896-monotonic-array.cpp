class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return true;
        
        vector<int>v1(nums);
            
            sort(v1.begin(),v1.end());
        
        if(nums==v1)
            return true;
        
        sort(v1.rbegin(),v1.rend());
        
        if(nums==v1)
            return true;
        
        return false;
    }
};