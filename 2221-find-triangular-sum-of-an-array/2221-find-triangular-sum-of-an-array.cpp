class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return nums[0]%10;
        
        if(n==2)
            return (nums[0]+nums[1])%10;
        
        int l=n;
    
         for(int j=n-1;j>=1;j--){
        for(int i=0;i<j;i++){
            nums[i]=(nums[i]+nums[i+1])%10;
         }
        }
        return nums[0];
            
    }
};