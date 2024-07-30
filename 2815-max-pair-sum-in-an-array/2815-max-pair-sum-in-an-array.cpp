class Solution {
public:
    int maxSum(vector<int>& nums) {
        
      int n=nums.size();
        int ans=-1;
      for(int i=0;i<n;i++){
          int mx1=find(nums[i]);
          for(int j=i+1;j<n;j++){
              if(find(nums[j])==mx1){
                  ans=max(ans,nums[i]+nums[j]);
              }
          }
      }  
      return ans;
    }
    
    int find(int x){
        int mx=0;
        while(x){
            mx=max(mx,x%10);
            x=x/10;
        }
        return mx;
    }
};