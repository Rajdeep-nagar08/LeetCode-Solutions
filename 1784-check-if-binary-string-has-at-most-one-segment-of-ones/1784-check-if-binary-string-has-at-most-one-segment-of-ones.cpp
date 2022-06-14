class Solution {
public:
    bool checkOnesSegment(string s) {
        
        
        int n=s.size();
        
        int i=0;
        
        bool f=false;
        
        while(i<n){
            
            if(s[i]=='1'){
                if(f==true)
                return false;
            
                   f=true;
                while(i<n && s[i]=='1')
                    i++;
            }
            else
                i++;
        }
        
        return true;
    }
};