/*

for each no. we have two choices

either we take it into the sum or not take it 


dp[target]= no of combinations we can form to make a sum==target
             , we have choices in range [0....n-1]
             
*/

int dp[1001];

class Solution {
public:
    int n;
    int combinationSum4(vector<int>& nums, int target) {
     
        n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,target,nums);
        
    }
    
    int find(int sum,int &target,vector<int>&nums){
    
     if(sum==target)
        return 1;
            
        if(dp[sum]!=-1)
            return dp[sum];
        
        int c=0;
        
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=target)
                c+=find(sum+nums[i],target,nums);
        }
        
        return dp[sum]=c;
    }
};