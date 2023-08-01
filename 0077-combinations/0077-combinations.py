
ans=[]
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        
        global ans
     
        ans=[]
        
        
        if n<k:
            return ans
        
        temp=[]
        
        self.find(1,n,k,temp)
        
        return ans;
    
    def find(self,i,j,k,temp):
        
        if k==0:
            ans.append(temp[:])
            return;
        
        for l in range(i,j+1,1):
            temp.append(l)
            k=k-1
            self.find(l+1,j,k,temp)
            k=k+1
            temp.pop()
            
        