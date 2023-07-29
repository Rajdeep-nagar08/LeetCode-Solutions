class Solution {
public: 
    vector<vector<double>> dp;
    double dfs(int A, int B){
        if (A<=0 && B>0) return 1;
        if (A<=0 && B<=0) return 0.5;
        if (A>0 && B<=0) return 0;
        if (dp[A][B]!=-1) return dp[A][B];
        double ans=0.25*(dfs(A-4, B)+dfs(A-3, B-1)+dfs(A-2, B-2)+dfs(A-1, B-3));
        return dp[A][B]=ans;
    }
    double soupServings(int n) {
        if (n>5000) return 1;
        dp.assign(201, vector<double>(201, -1));
        int N=ceil(n/25.0);
        return dfs(N, N);
    }
    
};