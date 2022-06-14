class Solution {
public:
    string replaceDigits(string s) {
        
        
        /*
        
        even index => letter 
        
        odd index => digit
        
        */
        
        int n=s.size();
        
        
        for(int i=0;i<n;i++){
            if(i%2==1){
                char ch=s[i-1];
                int no=s[i]-'0';
                
                s[i]=ch+no;
            }
        }
        
        return s;
    }
};