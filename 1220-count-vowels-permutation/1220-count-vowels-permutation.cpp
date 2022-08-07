/*

a=>e

e=> a/i

i=> a/e/o/u

o=> i/u

u=>a


dp[i][prev]= no of strings we can form of index range [i...n-1] if prev char 

is = prev [prev=1 (a) , 2(b) , 3(c) , 4(d) , 5(e)]

*/

int mod=1e9+7;

int dp[20001][6];   

class Solution {
public:
    int countVowelPermutation(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,n)%mod;
        
    }
    
    int find(int i,int prev,int n){
        
        if(i>=n)
            return 1;
        
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
        int c1=0;
        
        if(prev==0){
            for(int j=1;j<=5;j++){
               c1+=find(i+1,j,n)%mod; 
                c1=c1%mod;
            }
        }
        
        int c2=0;
        
        if(prev==1){
           c2+=find(i+1,2,n)%mod;
           c2%=mod;
        }
        
        if(prev==2){
            
           c2+=find(i+1,1,n)%mod+find(i+1,3,n)%mod; 
                       c2%=mod;

        }
        
        if(prev==3){
            
           for(int j=1;j<=5;j++){
               if(j!=3)
                   c2+=find(i+1,j,n)%mod;
                          c2%=mod;

           }
        }
        
        if(prev==4){
            
            c2+=find(i+1,3,n)%mod+find(i+1,5,n)%mod;
                       c2%=mod;

        }
        
        if(prev==5){
            
            c2+=find(i+1,1,n)%mod;
                       c2%=mod;

        }
        
        
        return dp[i][prev]=(c1%mod+c2%mod)%mod;
    }
};