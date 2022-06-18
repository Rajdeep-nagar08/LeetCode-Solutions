class Solution {
public:
    bool checkRecord(string s) {
        
        
        int n=s.size();
        
         
        int i=0;
        
        int a=0;
        
        while(i<n){
            
            if(s[i]=='P'){
                i++;
            }
            else if(s[i]=='A'){
                i++;
                a++;
                if(a>=2)
                    return false;
            }
            else{
                int l=0;
                
                while(i<n && s[i]=='L'){
                    i++;
                    l++;
                    if(l>=3)
                        return false;
                }
            }
        }
        
        return true;
    }
};