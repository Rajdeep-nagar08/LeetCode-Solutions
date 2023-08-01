

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
     
        ans=[]
        
        
        if n<k:
            return ans
        
        temp=[]
        
        self.find(1,n,k,temp,ans)
        
        return ans;
    
    def find(self,i,j,k,temp,ans):
        
        if k==0:
            ans.append(temp[:])
            return;
        
        for l in range(i,j+1,1):
            temp.append(l)
            k=k-1
            self.find(l+1,j,k,temp,ans)
            k=k+1
            temp.pop()
            
        