int mod=1e9+7;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mx_pos=min(steps,arrLen);
        vector<vector<long long int>>dp(steps+1,vector<long long int>(mx_pos+1,0));
         dp[0][0]=1;
        for(int i = 1; i <= steps; i++) {
            for(int j = 0; j < mx_pos; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1] + (j>0?dp[i-1][j-1]:0))%mod;
            }
        }
        
        return (int)dp[steps][0];
    }
};