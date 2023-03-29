
int dp[501][501];

class Solution {
public:
    int maxSatisfaction(vector<int>& satis) {
        
        
        int n=satis.size();
        
        /*
        
        after sorting in descending order
        
        for each no. we have two choices
        
        include it or not
        
        dp[i][k]= max codt from [i......n-1] if till now we have taken k dishes
        
        
        */
        
        
        memset(dp,-1,sizeof(dp));
        
        sort(satis.begin(),satis.end());
        
        return find(0,0,satis);
        
    }
    
    int find(int i, int k,vector<int>&satis){
        
        if(i>=satis.size())
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        
        int ans1=0;
        
        ans1=find(i+1,k,satis);
        
        int ans2=0;
        
        ans2=satis[i]*(k+1)+find(i+1,k+1,satis);
        
        return dp[i][k]=max(ans1,ans2);
        
    }
};