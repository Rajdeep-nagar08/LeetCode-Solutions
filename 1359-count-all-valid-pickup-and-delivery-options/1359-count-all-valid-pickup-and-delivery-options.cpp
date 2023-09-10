/*
there are n! ways to place n pickup options

for each pickup option we have 1*3*5*7*...(2n-1) delivery options

so total ways = n! * (1*3*5*7*...2n-1)

*/


int mod=1e9+7;
#define lln long long int
class Solution {
public:
    int countOrders(int n) {
      
        lln ans1=1;
        
        for(int i=1;i<=n;i++){
          ans1=ans1*i%mod;  
        }
        
        lln ans2=1;
        
        for(int i=1;i<=2*n-1;i+=2){
            ans2=ans2*i%mod;
        }
        
        return ans1*ans2%mod;
         
    }
};