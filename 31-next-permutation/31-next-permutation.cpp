
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
       int n=nums.size();
      int i;
      for(i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1])
          break;
      }
       
      if(i==-1)  // whole array in decreasing order, so return reverse of it
        return reverse(nums.begin(),nums.end());
      
      // reverse the array part which is in decreasing order
         reverse(nums.begin()+i+1,nums.end());
      
        // find next greater to pivot and reverse it with that 
      auto it=upper_bound(nums.begin()+i+1,nums.end(),nums[i]);
      
      swap(*it,nums[i]);
       
    }
};