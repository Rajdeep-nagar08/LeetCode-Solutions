import numpy as np

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        
        
        lst=[int(x) for x in str(n)]
        
        return np.prod(lst)-np.sum(lst)
            
            
