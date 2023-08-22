class Solution {
public:
    string convertToTitle(int cn) {
        
        string ans="";
        
    
        while(cn>0){
            
            cn--;
            
            int x=cn%26;
            
            ans+=(x+'A');
            
            cn=cn/26;
            
            
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};