class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0 || n<0)
            return false;
        double x;
        
        
        x=log10(n)/log10(3);
        if(int(x)==x)
            return true;
        else 
            return false;
        
        
    }
};