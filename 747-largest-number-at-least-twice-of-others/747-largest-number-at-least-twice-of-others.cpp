class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       
        int n=nums.size();
        
        int mx1=-1,mx2=-1;
        
        int idx;
        
        for(int i=0;i<n;i++){
           if(nums[i]>mx1){
               mx1=nums[i];
               idx=i;
           }
        }
        
        for(int i=0;i<n;i++){
           if(nums[i]!=mx1){
               mx2=max(mx2,nums[i]);
           }
        }
        
        
        if(mx1>=2*mx2)
            return idx;
        
        
        return -1;
        
    }
};