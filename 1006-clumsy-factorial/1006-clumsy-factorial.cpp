class Solution {
public:
    int clumsy(int n) {
      
        int ans=0;
        
        bool flag=true;
        
        int no;
        
        while(true){
            
            if(flag){
                flag=false;
              no=n;
            }
            else
                no=-n;
            
            n--;
            
            if(n>0){
                no=no*n;
            }
            else
                break;
            
            n--;
            
            if(n>0){
               no=no/n; 
            }
            else
                break;
            
            n--;
            
            if(n>0){
                no=no+n;
            }
            else
                break;
            
            n--;
                        
                ans=ans+no;
            
        }
        
        if(flag)
            return no;
        
        return ans+no;
        
    }
};