dp={}

class Solution:
    def strangePrinter(self, s: str) -> int:
        global dp
        dp = {}
        return self.get(0, len(s) - 1, s)
    
    def get(self, i: int, j: int, s: str) -> int:
        if i == j:
            return 1
        if (i, j) in dp:
            return dp[(i, j)]
        
        ans = float('inf')
        for k in range(i, j):  # not do k<=j otherwise K+1 will be out of bound
            ans = min(ans, self.get(i, k, s) + self.get(k + 1, j, s))
        
        if s[i] == s[j]:  # only one turn needed, so decrease by 1 as both are same
            ans -= 1

        dp[(i, j)] = ans
        return ans
    
    
        