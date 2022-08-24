class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        while(n){
            if(n%3==0)
                n=n/3;
            else{
                n--;
                if(n%3!=0)
                    return false;
                
                n=n/3;
            }
        }
        
        return true;
    }
};