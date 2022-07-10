
int dp[1001];

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        int n=cost.size();
        
        
        /*
        
        
        dp[i] = min cost to move from [i....n-1]
        
        
        */
        
        
        memset(dp,-1,sizeof(dp));
        
        
        return min(find(0,cost),find(1,cost));
        
    }
    
    int find(int i,vector<int>&cost){
        int n=cost.size();
        
        if(i>=n){
            return 0;
        }
        
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c1=INT_MAX,c2=INT_MAX;
        
        
        c1=min(c1,cost[i]+find(i+1,cost));
        
        
        c2=min(c2,cost[i]+find(i+2,cost));
        
        
        return dp[i]=min(c1,c2);
    
        
    }
};