int dp[1001][2001];
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        
        
        int n=p.size();
        
        /*
        dp[i][j]=max total value we can collect from [i...n-1] using j              steps
        
        choosing from ith pile or not choosing
        
        
        dp[i][j]=max(dp[i+1][j],sum(nums[0]...nums[k1-1])+dp[i+1][k-k1]);
        
        
        Ans= dp[0][k];
        
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,p,k);
        
    }
    
    int find(int i,vector<vector<int>>&p,int k){
        
        if(i>=p.size() || k<=0)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int mx=INT_MIN;
        
        mx=max(mx,find(i+1,p,k));
        
         int sum=0;
        for(int k1=0;k1<k;k1++){

    if(k1<p[i].size()){
        sum+=p[i][k1];
        
         mx=max(mx,sum+find(i+1,p,k-k1-1));

        }
    }
        
        return dp[i][k]=mx;
        
    }
};