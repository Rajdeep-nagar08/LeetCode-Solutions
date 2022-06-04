class Solution {
public:
    string strWithout3a3b(int a, int b) {
      
        string ans="";
        
            while(a>b){
                
                if(a){
                    ans+="a";
                    a--;
                }
                 if(a){
                    ans+="a";
                    a--;
                }
                if(b){
                    ans+="b";
                    b--;
                }
            }
        
           while(b>a){
                
                if(b){
                    ans+="b";
                    b--;
                }
                 if(b){
                    ans+="b";
                    b--;
                }
               if(a){
                    ans+="a";
                    a--;
                }
            }
        
        while(a>0 || b>0) {
            if(a){
              ans+="a";
                a--;
            }
            if(b){
              ans+="b";
              b--;
            }
          }
        
        return ans;
    }
};