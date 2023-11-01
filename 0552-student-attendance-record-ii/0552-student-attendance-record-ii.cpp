int dp[100001][3][4];
class Solution {
public:
    int MOD=1000000007;
    int solve(int n, int remA, int remL){
        if(n==0) return 1;

        if(dp[n][remA][remL]!=-1)
            return dp[n][remA][remL];
        //if p
        int ans=solve(n-1, remA,2);

        if(remA>0){
             ans+=solve(n-1,remA-1,2);
             ans=ans%MOD;
        }

        if(remL>0) {
            ans+=solve(n-1,remA,remL-1);
            ans=ans%MOD;
            }

        return dp[n][remA][remL]=ans%MOD;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        
        return solve(n,1,2);
    }
};