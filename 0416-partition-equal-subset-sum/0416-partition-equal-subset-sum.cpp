#define lln long long int
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        lln sum = 0;
        int n = nums.size();
        for (int x : nums)
            sum += x;
        if (sum % 2)
            return false;
        
        vector<vector<int>> memo(n, vector<int>(sum / 2 + 1, -1));
        return canPartitionRecursive(nums, sum / 2, 0, memo);
    }
    
private:
    bool canPartitionRecursive(vector<int>& nums, int target, int currentIndex, vector<vector<int>>& memo) {
        if (target == 0)
            return true;
        if (currentIndex >= nums.size())
            return false;

        if (memo[currentIndex][target] != -1)
            return memo[currentIndex][target];

        if (nums[currentIndex] <= target) {
            if (canPartitionRecursive(nums, target - nums[currentIndex], currentIndex + 1, memo)) {
                memo[currentIndex][target] = 1;
                return true;
            }
        }

        memo[currentIndex][target] = canPartitionRecursive(nums, target, currentIndex + 1, memo) ? 1 : 0;
        return memo[currentIndex][target];
    }
};
