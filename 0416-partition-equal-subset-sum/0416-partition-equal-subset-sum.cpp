#define lln long long int

lln dp[201][10001];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        lln sum = 0;
        int n = nums.size();
        for (int x : nums)
            sum += x;
        if (sum % 2)
            return false;
            
        memset(dp,-1,sizeof(dp));
            
        return find(0, nums,sum/2);
    }
    
private:
    bool find(int i,vector<int>&nums, int target) {
       
       if (target == 0)
            return true;
            
        if (i>= nums.size())
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        if (nums[i] <= target) {
            if (find(i+1,nums,target-nums[i])) {
                dp[i][target] = 1;
                return true;
            }
        }

        dp[i][target] = find(i+1,nums,target)?1:0;
        
        return dp[i][target];
    }
};
