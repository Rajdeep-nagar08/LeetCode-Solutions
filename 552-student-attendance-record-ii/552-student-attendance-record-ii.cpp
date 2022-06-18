/*

no of possible strings of length =n 

where , no of 'A'=0 or 1

No of consecutive 'L' < 3

And no boundation on 'P'


so for each position we have three choices,
1. Put 'P' on this position

2. Put 'A' on this positiuon such that no of 'A' < 2

3. Put 'L' on this position (there shouldnot be 3 consecutive L's)

As we have choices for each position , so we can think about dp

dp[i][a][l] = no of valid string we can form in [i...n-1]

if we no of 'A' till now = a

no of conscutive l till now = l

Note: a<2 and l<3 always


*/

#define lln long long int 

lln dp[100001][3][4];


int mod=1e9+7;

class Solution {
public:
    int checkRecord(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        
        return find(0,0,0,n)%mod;
        
    }
    
    lln find(int i,int a,int l,int n){
        
        if(i>=n){
            return 1;
        }
        
        if(dp[i][a][l]!=-1)
            return dp[i][a][l];
        
        lln c1=0,c2=0,c3=0;
        
        // put 'P' on this index
        
        c1=c1+find(i+1,a,0,n);
        
        // put 'A' on this index
        
        if(a<=0){
            c2=c2+find(i+1,a+1,0,n);
        }
        
        // put 'L' on this index
        
        if(l<=1){
            c3=c3+find(i+1,a,l+1,n);
        }
        
        return dp[i][a][l]=(c1+c2+c3)%mod;
        
    }
};