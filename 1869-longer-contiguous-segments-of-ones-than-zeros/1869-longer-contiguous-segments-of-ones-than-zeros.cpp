class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int one=0;
        
        int zero=0;
        
        int n=s.size();
        
        int i=0;
        
        while(i<n){
            
            int o=0,z=0;
            
            if(s[i]=='0')
                z++;
            else
                o++;
            
            i++;
            
            while(i<n and s[i]==s[i-1]){
                if(s[i]=='0')
                    z++;
                else
                    o++;
                i++;
            }
            
            one=max(o,one);
            
            zero=max(z,zero);
                
        }
        
        return one>zero;
        
    }
};