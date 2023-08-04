class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        
        ch=str(n)
    
        prod=1
        
        sm=0
        
        for c in ch:
            prod=prod*int(c)
            sm+=int(c)
            
        
        return prod-sm
            
            
