class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        
        ans=[]
        
        n=len(nums)
        
        self.find(0,n,nums,ans)
        
        return ans
    
    def find(self,i,n,nums,ans):
        
        if i >= n:
            ans.append(nums[:])
            return
        
        for j in range(i,n,1):
            nums[i],nums[j]=nums[j],nums[i]
            self.find(i+1,n,nums,ans)
            nums[i],nums[j]=nums[j],nums[i]
        
        