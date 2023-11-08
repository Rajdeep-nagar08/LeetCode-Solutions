class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        
       
        
         int min_m = abs(fx - sx) + abs(fy - sy) - min(abs(fx - sx), abs(fy - sy));
    
  
          if (t < min_m) {
        return false;
    }
    
        
         
        if(t==1 && sx==fx && sy==fy)
            return false;
        
        
       
        
       return true;
        
        
    }
};