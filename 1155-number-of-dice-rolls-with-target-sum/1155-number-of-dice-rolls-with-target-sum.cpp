/*

n dices

each dice has k faces [1....k]

no. of ways to roll n dices so that sum of upper face == target


For each dice among n dices we have k choices for upper face

As we have choices, we can think about dp


n<=30


k<=30


target<=1000


dp[i][target]= no. of ways to get sum= target, using 

[i......n] dice , for each dice we have k choices (will runs a for loop of
size k)


Ans= dp[1][target]


*/

int dp[31][1001];

int mod=1e9+7;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        
        memset(dp,-1,sizeof(dp));
        
        return find(1,target,n,k)%mod;
        
    }
    
    int find(int i,int target,int n,int k){
        
        if(i>n){
            
            if(target==0)
                return 1;
            
            return 0;
        }
        
        if(dp[i][target]!=-1)
            return dp[i][target];
        
        int ch=0;
        
        for(int f=1;f<=k;f++){
            
            if(target-f>=0){
                ch+=find(i+1,target-f,n,k);
                ch%=mod;
            }
        }
        
        return dp[i][target]=ch%mod;
        
    }
};