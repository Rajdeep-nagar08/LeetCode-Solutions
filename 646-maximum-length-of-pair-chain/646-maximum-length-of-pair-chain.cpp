class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            int mx=0;
            int c=pairs[i][0];
            for(int j=0;j<i;j++){
                int b=pairs[j][1];
                if(b<c)
                    mx=max(mx,dp[j]);
            }
            dp[i]=dp[i]+mx;
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};


/*
dp[i]=length of longest chain ends at index i
dp[i]= max(all dp[j], j<i and b<c)
*/

