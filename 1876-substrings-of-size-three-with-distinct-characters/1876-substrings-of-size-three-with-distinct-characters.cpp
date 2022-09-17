class Solution {
public:
    int countGoodSubstrings(string s) {
        
        
        
        int n=s.size();
        
        if(n<3)
            return 0;
        
        char a=s[0];
        
        char b=s[1];
        
        char c=s[2];
        
        int count=0;
        
        if(a!=b && a!=c && b!=c)
            count++;
        
        for(int i=3;i<n;i++){
            
            a=b;
            b=c;
            c=s[i];
            
              
        if(a!=b && a!=c && b!=c)
            count++;
            
        }
        
        return count;
    }
};