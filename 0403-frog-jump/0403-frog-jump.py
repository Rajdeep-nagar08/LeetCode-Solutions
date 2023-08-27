class Solution:
    def canCross(self, stones: List[int]) -> bool:

        mp={}
        
        dp={}
        
        n=len(stones)
        
        for i in range(n):
            mp[stones[i]]=i
            
        if stones[1]-stones[0]>1:
            return False
        
        def find(i,k,no):
            
            if i==n-1:
                return True
            
            if i>=n or i<0:
                return False
            
            if (i,k) in dp:
                return dp[(i,k)]
            
            op1,op2,op3=False,False,False
            
            if k!=1 and no+k-1 in mp:
                op1=find(mp[no+k-1],k-1,no+k-1)
            
            if no+k in mp:
                op2=find(mp[no+k],k,no+k)
                
            if no+k+1 in mp:
                op3=find(mp[no+k+1],k+1,no+k+1)
                
            dp[(i,k)]= op1 or op2 or op3
            
            return dp[(i,k)]
        
        
        return find(1,1,stones[1])
        