#    NNNN  [j] YYYY  => penalty = count of N + count of Y


class Solution:
    def bestClosingTime(self, cust: str) -> int:
        
        
        y=0
        for i in range(len(cust)):
            if cust[i]=='Y':
                y=y+1
        
        n=0
        mnPen=100000
        mnIdx=0
        
        for i in range(len(cust)):
            if n+y<mnPen:
                mnPen=n+y
                mnIdx=i
            if cust[i]=='N':
                n=n+1
            if cust[i]=='Y':
                y=y-1
        
        
        if n+y<mnPen:
            return len(cust)
        
        return mnIdx
        
        


        
        
        