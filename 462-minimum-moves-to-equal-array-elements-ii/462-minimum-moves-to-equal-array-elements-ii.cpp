class Solution {
public:
    int minMoves2(vector<int>& nums) {
     
       int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=nums[n/2];
        
       long long int ans=0;
        
      for(int x:nums)
          ans+= abs(x-mid);
        
      return ans;
    }
};