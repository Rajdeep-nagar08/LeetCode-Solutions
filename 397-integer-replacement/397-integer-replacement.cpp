#define lln long long int
class Solution {
public:
    int integerReplacement(int n) {
        
        lln n1=n;
        
        return find(n1);
    }
    
    lln find(lln n){
        
         if(n==1)
            return 0;
   /*     
        if(n>1ll*2*INT_MAX || n<1)
            return INT_MAX;
        
        */
        if(n%2==0)
            return 1+find(n/2);
       /* 
        else if(n==INT_MAX)
            return 1+integerReplacement(n-1);
          */  
        
     return min(1+find(n+1),1+find(n-1));

        
    }
};