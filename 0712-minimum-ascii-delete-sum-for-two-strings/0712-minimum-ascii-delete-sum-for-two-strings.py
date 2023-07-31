dp = [[-1 for _ in range(1001)] for _ in range(1001)]

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        
        global dp
        dp = [[-1 for _ in range(1001)] for _ in range(1001)]
        return self._check(0, 0, s1, s2)

    
    def _check(self, i, j, s1, s2):
        global dp
        if i >= len(s1):
            count = 0
            for k in range(j, len(s2)):
                count += ord(s2[k])
            return count

        if j >= len(s2):
            count = 0
            for k in range(i, len(s1)):
                count += ord(s1[k])
            return count
        
        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            dp[i][j] = self._check(i + 1, j + 1, s1, s2)
        else:
            dp[i][j] = min(
                ord(s1[i]) + self._check(i + 1, j, s1, s2),
                ord(s2[j]) + self._check(i, j + 1, s1, s2)
            )

        return dp[i][j]







        