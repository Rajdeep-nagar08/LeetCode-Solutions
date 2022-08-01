class Solution {
public:
    #define ll long long
    ll n, m;
    ll INF = 1000000000000ll;
    vector<vector<vector<ll>>> DP;
    long long dp(ll i, ll j, int dir, vector<vector<int>>& a) {
        if (j < 0 || j >= m)
            return -INF;
        if (i == n)
            return 0;
        if (DP[i][j][dir] != -1)
            return DP[i][j][dir];
        ll x = a[i][j];
        ll ans = x + dp(i + 1, j, 0, a);
        if (dir != 1)
            ans = max(ans, -1 + dp(i, j - 1, 2, a));
        if (dir != 2)
            ans = max(ans, -1 + dp(i, j + 1, 1, a));
        return DP[i][j][dir] = ans;
    }
    long long maxPoints(vector<vector<int>> &a) {
        n = a.size(), m = a[0].size();
        DP.resize(n, vector<vector<ll>>(m, vector<ll>(3, -1)));
        ll ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            ans = max(ans, dp(0, i, 0, a));
        }
        return ans;
    }
};