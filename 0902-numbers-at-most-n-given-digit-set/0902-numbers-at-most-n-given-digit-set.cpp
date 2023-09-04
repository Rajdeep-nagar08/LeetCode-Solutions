#define lln long long int
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string str=to_string(n);
        int lN=str.length();
        
        int lD=digits.size();
        
        
        lln ans=0;
        
        for(int i=1;i<lN;i++){
            ans+=pow(lD,i);
        }
        
        for(int i=0;i<lN;i++){
            bool isSame=false;
            
            for(string dg:digits){
                
            if(dg[0]==str[i]){
                isSame=true;
                continue;
            }
                
           else if(dg[0] < str[i])
               ans+=pow(lD,lN-i-1);
               }
               
            if(isSame==false)
               return ans;
               }
               
        return ans+1;
    }
};