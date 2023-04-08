class Solution {
public:
    bool isHappy(int n) {
        
        
        
        string str=to_string(n);
        
        
        int t=0;
        
        while(t<=500){
            int sum=0;
            for(char ch:str){
                sum+=(ch-'0')*(ch-'0');
            }
            
            if(sum==1)
                return true;
            
            if(sum==0)
                return false;
            
            str=to_string(sum);
            
            t++;
        }
        
        return false;
        
    }
};