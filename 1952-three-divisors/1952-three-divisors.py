from math import sqrt

class Solution:
    def isThree(self, n: int) -> bool:
        
        count=0
        
        for i in range(1,n+1):
            if n%i==0:
                count=count+1
            
            if count>3:
                return False;
        
        if count==3:
            return True
        
        return False
        
        
        