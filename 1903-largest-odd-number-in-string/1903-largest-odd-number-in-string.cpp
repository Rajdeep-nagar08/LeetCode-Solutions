class Solution {
public:
    string largestOddNumber(string num) {
        
        
        int n=num.size();
        
        int i=n-1;
        
        int l=n;
        
        while(i>=0){
            int x=num[i]-'0';
            
            if(x%2)
                break;
            
            i--,l--;
        }
        
        if(i>=0)
            return num.substr(0,l);
        
        return "";
        
    }
};