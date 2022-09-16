class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        
        int n=nums.size();
    
        
        int temp=nums[0];
        
        int ans=temp;
        
        int i=1;
        
        while(i<n){
            if(nums[i]>nums[i-1]){
                temp+=nums[i];
            }
            else{
                temp=nums[i];
            }
            
            ans=max(ans,temp);

            i++;
        }
        
        return ans;
    }
};