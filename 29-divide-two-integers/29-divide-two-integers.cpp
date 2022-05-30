class Solution {
public:
    int divide(int d1, int d2) {
        
        if(d1==INT_MIN){
            if(d2==-1)
                return INT_MAX;
            else
                return d1/d2;
        }
        
        return d1/d2;
    }
};