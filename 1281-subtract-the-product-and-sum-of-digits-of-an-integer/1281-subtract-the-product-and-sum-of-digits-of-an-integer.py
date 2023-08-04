

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        
        
        lst=[int(x) for x in str(n)]
        
        return prod(lst)-sum(lst)
            
            
