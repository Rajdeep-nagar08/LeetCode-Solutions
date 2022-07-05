class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        
        int n=nums.size();
        
        int i=0;
        
        
        while(i<n){
            
            if(i+1<n && nums[i]==nums[i+1])
                return nums[i];
            
            if(i+2<n && nums[i]==nums[i+2])
                return nums[i];
            
            if(i+3<n && nums[i]==nums[i+3])
                return nums[i];
            
            i++;
        }
        
        return -1;
        
    }
};