class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        dp={}
        
        def find(i,j):
            if i==m-1 and j==n-1:
                return 1
            
            if i>=m or j>=n:
                return 0
            
            if (i,j) in dp:
                return dp[(i,j)]
        
            dp[(i,j)]=find(i+1,j)+find(i,j+1)
            return dp[(i,j)]
        
        return find(0,0)
        
        
        
        
#         dp[i][j] = no of unique paths that can be taken from [i,j] to reach [n-1,m-1] ans = dp[0][0]


        
        
        