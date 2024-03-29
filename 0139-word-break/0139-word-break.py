

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    
        n=len(s)
        
        m=len(wordDict)
        
        
        
        self.dp=[-1 for _ in range(n+1)]

        
        mp=defaultdict(int)
        
        for i in range(m):
            mp[wordDict[i]]+=1
            
            
            
        return self.find(0,n,s,mp)
    
    
    
    def find(self,i,n,s,mp):
        
        if i>=n:
            return True;
        
        if self.dp[i]!=-1:
            return self.dp[i]
        
        f1=False
        f2=False
        
        for j in range(i,n,1):
            if mp[s[i:j+1]]>0:
                f1=True
                f3=True
                f3=f3 & self.find(j+1,n,s,mp)
                
                if f3==True:
                    f2=True
                    break
        
        
        if f1==True:
            self.dp[i]=f2
            return self.dp[i]
        
        self.dp[i]=False
        return self.dp[i]
    
    