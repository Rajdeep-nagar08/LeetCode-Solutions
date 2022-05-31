#define lln long long int
unordered_map<lln,int>mp;
class Solution {
public:
    int integerReplacement(int n) {
        
        lln n1=n;
        
        return find(n1);
    }
    
    lln find(lln n){
        
         if(n==1)
            return 0;
        
        if(mp.count(n)==1)
            return mp[n];
  
        if(n%2==0)
            return mp[n]=1+find(n/2);
      
     return mp[n]=min(1+find(n+1),1+find(n-1));

        
    }
};