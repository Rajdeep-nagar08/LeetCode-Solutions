#define lln long long int
class Solution {
  int mod=1e9+7;
public:
    int numTilings(int n) {
       if(n<=2)
         return n;
      
      vector<lln>f(n+1,0),f1(n+1,0);
      
      f[0]=0,f[1]=1,f[2]=2;
      f1[0]=0,f1[1]=1,f1[2]=2;
      
      for(int i=3;i<=n;i++){
        f[i]=(f[i-1]+f[i-2]+2*f1[i-2])%mod;
        f1[i]=(f[i-1]+f1[i-1])%mod;
      }
      
      return f[n];
      
    }
};