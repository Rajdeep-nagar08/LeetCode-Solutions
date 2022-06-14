class Solution {
public:
    bool squareIsWhite(string c) {
        
        
        /*
        
        white => true
         
         Black => false
         
         */
        
        
        int n1=c[0]-'a'+1;
        
        int n2=c[1]-'0';
        
        if(n1%2==1){
            if(n2%2==1)
                return false;
            else
                return true;
        }
        
        else{
            
             if(n2%2==0)
                return false;
            else
                return true;
            
        }
        
        
        return true;
    }
};