
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>ans(n);
      
        for(int i=0;i<n;i++){
            
            int c=0;
            
            for(int j=0;j<n;j++){
                
                if(nums[j]<nums[i])
                    c++;
            }
            
            ans[i]=c;
        }
        
        return ans;
        
    }
};