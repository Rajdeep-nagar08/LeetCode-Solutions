/*

at each index i we have three choices, either be at the same index i, or move to i+1, or move to i-1

as we have choices we can think about dp

dp[i][j] = no of ways in which we can will be at index 0, using j steps, if currently we are at ith index


ans= dp[0][steps]

*/


int mod=1e9+7;

unordered_map<int, unordered_map<int,int>>dp;

#define lln long long int

class Solution {
public:
    int numWays(int steps, int arrLen) {
       
        dp.clear();
                
        return find(0, steps, arrLen);
        
    }
    
    int find(int i, int steps, int n){
        if(i==0 && steps==0){
            return 1;
        }
        
        if(i<0 || i>=n)
            return 0;
        
        if(steps<=0)
            return 0;
        
        if(dp[i].count(steps)==1)
            return dp[i][steps];
        
 lln ans= (1ll*find(i,steps-1,n)%mod + 1ll*find(i+1,steps-1,n)%mod + 1ll*find(i-1,steps-1,n)%mod)%mod;
 ans%=mod;
        
        return dp[i][steps]=ans%mod;
    }
};
