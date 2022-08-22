class Solution {
public:
    bool isPowerOfFour(int n) {
      
  if(n<=0)
      return false;
        
        
        int no=log2(n);
        
      //  cout<<no<<endl;
        
        no=no/2;
        
       // cout<<no<<endl;
        
       if(pow(4,no)==n)
           return true;
        
        return false;
    }
};