

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    
        
        n=len(s)
        
        m=len(wordDict)
        
        dp=[-1 for _ in range(n+1)]

        
        mp=defaultdict(int)
        
        for i in range(m):
            mp[wordDict[i]]+=1
            
            
            
        return self.find(0,n,s,mp,dp)
    
    
    
    def find(self,i,n,s,mp,dp):
        
        if i>=n:
            return True;
        
        if dp[i]!=-1:
            return dp[i]
        
        f1=False
        f2=False
        
        for j in range(i,n,1):
            if mp[s[i:j+1]]>0:
                f1=True
                f3=True
                f3=f3 & self.find(j+1,n,s,mp,dp)
                
                if f3==True:
                    f2=True
                    break
        
        
        if f1==True:
            dp[i]=f2
            return dp[i]
        
        dp[i]=False
        return dp[i]
    
    