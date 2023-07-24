#define lln double
class Solution {
public:
    double myPow(double x, int n) {
    
      if(n>0)
        return find(x,n);
      else
      return 1/find(x,n);
    }
  
     lln find(double x, int n){
       if(n==0)
         return 1.0;
       if(n==1 || n==-1)
          return x;
       

       if(n%2==0){
        lln temp= find(x,n/2);
         return (double)temp*(double)temp;
       }
       
       else{
        lln temp= find(x,n/2);
          return (double)temp*(double)temp*(double)x;

       }
       
     }
};
