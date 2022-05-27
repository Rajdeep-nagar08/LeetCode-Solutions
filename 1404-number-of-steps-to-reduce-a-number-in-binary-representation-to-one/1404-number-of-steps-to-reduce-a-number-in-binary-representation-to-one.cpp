class Solution {
public:
    int numSteps(string s) {
        
        
        int i=s.size()-1;
                
        int carry=0;   // carry of addition
        
        int ans=0;
        
        while(i>=1){
            
            int bit=(s[i]-'0');
            
            if(bit+carry==1){
                // number is odd , add 1 to it
                // 1+1=0 (carry =1)
                s[i]='0';
                carry=1;
                ans++;
                
                // NOW number becomes even, devide it by 2 , or right shift
                i--;
                ans++;
                
            }
            else{
                // number is even , simply do right shift
                i--;
                ans++;
            }
        }
        
        if(carry==1)
            ans++;
        
        return ans;
    }
};