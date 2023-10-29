class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    
        if(n==0)
            return 1;
        
        int ans=0;
        
        for(int digits=1;digits<=n;digits++){
            
            if(digits==1){
                ans+=10;
            }
            else if(digits==2){
                ans+=81;
            }
            else{
                int t=9;
                int temp=9;
                for(int x=1;x<digits;x++){
                    temp=temp*t;
                    t--;
                }
                ans+=temp;
            }
        }
        return ans;
    }
};