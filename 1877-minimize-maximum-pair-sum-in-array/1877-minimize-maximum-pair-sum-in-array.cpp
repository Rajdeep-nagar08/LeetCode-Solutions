class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
      sort(nums.begin(),nums.end());
      
      int i=0,j=nums.size()-1;
      int mx=0;
      while(i<j){
        mx=max(mx,nums[i]+nums[j]);
        i++;
        j--;
      }
      return mx;
    }
};