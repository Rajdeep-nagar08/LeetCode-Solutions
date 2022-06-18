class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    
        
        int n=nums.size();
        
        int ans=0;
        
        int i=0;
        
        
        while(i<n){
            if(nums[i]==0){
                i++;
                continue;
            }
            
            int count=0;
            
            while(i<n && nums[i]==1){
                count++;
                i++;
            }
            ans=max(ans,count);
        }
        
        return ans;
    }
    
};