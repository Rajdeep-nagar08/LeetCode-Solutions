/*

at each index i we have three choices, either be at the same index i, or move to i+1, or move to i-1

as we have choices we can think about dp

dp[i][j] = no of ways in which we can will be at index 0, using j steps, if currently we are at ith index


NOTE : i can be maximum upto steps it means i <= steps always

so array size = min(arraylen,step) * steps

ans= dp[0][steps]

*/


int mod=1e9+7;


int dp[501][501];

#define lln long long int

class Solution {
public:
    int numWays(int steps, int arrLen) {
       
        memset(dp,-1,sizeof(dp));
        
        return find(0, steps, min(arrLen,steps));
        
    }
    
    int find(int i, int steps, int n){
        if(i==0 && steps==0){
            return 1;
        }
        
        if(i<0 || i>=n)
            return 0;
        
        if(steps<=0)
            return 0;
        
        if(dp[i][steps]!=-1)
            return dp[i][steps];
        
 lln ans= (1ll*find(i,steps-1,n)%mod + 1ll*find(i+1,steps-1,n)%mod + 1ll*find(i-1,steps-1,n)%mod)%mod;
        
 ans%=mod;
        
        return dp[i][steps]=ans%mod;
    }
};
