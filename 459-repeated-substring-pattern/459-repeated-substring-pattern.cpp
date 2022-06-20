class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.size();
        
        int i=0;
        
        if(n==1)
            return false;
        
        string str;
        
        for(int i=0;i<n/2;i++){
            str+=s[i];
            int l=str.size();
            int j=0;
            bool f=true;
            while(j<n){
                if(j+l-1>=n){
                    f=false;
                    break;
                }
                string s1=s.substr(j,l);
                if(s1!=str){
                    f=false;
                    break;
                }
                j=j+l;
            }
            if(f)
                return true;
        }
        
        return false;
        
    }
};