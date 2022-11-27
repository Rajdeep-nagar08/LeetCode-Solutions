/*
We memoise differences between the current element, and all elements before it. Then, when we see some difference again, we can tell how many elements form an arithmetic sequence with that difference.
*/

#define lln long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n=nums.size();
      vector<unordered_map<lln,lln>>dp(n);   // [index,{diff,count}]
      lln ans=0;
      
      for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          lln diff= (lln)nums[i]-(lln)nums[j];
          dp[i][diff]++;
          
          if(dp[j].find(diff)!=dp[j].end())  // checking if same difference exist earlier
            dp[i][diff]=dp[i][diff]+dp[j][diff];
          
          ans=ans+dp[j][diff];
        }
      }
      
      return ans;
    }
};

/*
We use a vector of unordered_maps for our dynamic programming.
The vector is used as follows: [ index, {diff, count} ].
For each index, we have all common differences and count arithmetic slices up to that index.

We iterate through the given vector nums, and for each number we iterate again from the beginning to there.
diff is the difference, so we can add 1 to the counter of dp[i][diff].
If we already have a key for diff in dp[j], we can add to dp[i][diff] all the count that we had by dp[j][diff]. And that's what we add to our res.

*/