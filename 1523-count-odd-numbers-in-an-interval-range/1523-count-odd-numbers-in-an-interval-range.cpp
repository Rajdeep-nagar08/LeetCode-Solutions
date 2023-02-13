class Solution {
public:
    int countOdds(int l, int h) {
        
        
        if(l%2==0 && h%2==0){
           return (h-l)/2; 
            
        }
            
            return ((h-l)/2+1);
    
        
    }
};