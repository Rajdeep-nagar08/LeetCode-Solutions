/*


need to maximize the cost

select atmost k events

[a,b] [c,d]  => c > b




*/


class Solution {
public:
    int solve(vector<vector<int>>& ev, int k, int ind, vector<vector<int>> &dp){
        int n= ev.size();
        if(k<=0 or ind >=n) 
            return 0;
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
        
        int a= solve(ev, k, ind+1, dp);
        
        int i=ind;
        
        while(ind<n and ev[ind][0]<=ev[i][1]) 
            ind++;
        
        int b= ev[i][2]+ solve(ev, k-1, ind, dp);

        return dp[i][k]= max(a,b);
    }
    
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n= events.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(events, k, 0 , dp);
    }
};