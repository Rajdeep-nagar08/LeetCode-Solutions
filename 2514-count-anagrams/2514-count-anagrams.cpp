#define lln long long int
int mod=1e9+7;

class Solution {
public:
    int countAnagrams(string s) {
        
        
        int n=s.size();
        
        vector<lln>fact(n+1,0);
        
        fact[1]=1;
        
        for(int i=2;i<=n;i++){
            fact[i]=fact[i-1]*i%mod;
        }
        
        
     lln ans=1;   
        
    
stringstream ss(s);
string word;

while(ss>>word)
{
    
        unordered_map<char,int>mp;

    for(char ch:word){
        mp[ch]++;
    }
    
    lln f=fact[(int)word.size()];
    

    for(auto it:mp){
        
        lln l=fact[it.second];
        
        f=aDevb(f,l,mod);
        
    }
    
  //  cout<<f<<endl;
    
    ans=1ll*ans*f%mod;
    
}             
    return ans;
    
}
    
    
    
 lln pw(lln b, lln n,lln m){ // b^n  using binarb ebponentiation
        if (n == 0) 
            return 1;
        lln u = pw(b,n/2,m);
        u = (1ll*u*u)%m;
        if(n%2 == 1)
         u = (1ll*u*b)%m;
        return u;
    }
    
    
    
      lln moduloInverse(lln a,lln m){
        // inverse modulo of a under mod m

        return pw(a,m-2,m)%m;
    }

    lln aDevb(lln a,lln b,lln m){ 
        a=a%m;
        b=b%m;
       
        lln inv_bm=moduloInverse(b,m);   
        // inverse modulo of b under mod m
      
        return a*inv_bm % m;
    }

    

        
};