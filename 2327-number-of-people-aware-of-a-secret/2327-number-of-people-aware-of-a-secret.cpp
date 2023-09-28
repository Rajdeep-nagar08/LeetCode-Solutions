int dp[1001];

int mod=1e9+7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans= find(1, n, delay, forget)%mod;
        
        if(1+forget>n)
            ans++;
        
        return ans;
        
    }
    
    int find(int d, int n, int delay, int forget){
        
        if(d>n)
            return -1;
        
        if(dp[d]!=-1)
            return dp[d];
        
        int ans=0;
                
        for(int i=d+delay; i<d+forget; i++){
        
            ans+= 1 + find(i,n,delay,forget);
            
            if(i+forget<=n)
                ans=ans-1;
            
            ans=ans%mod;
            
        }
        
        return dp[d]=ans%mod;
    }
};