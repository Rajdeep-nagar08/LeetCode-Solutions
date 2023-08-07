# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        self.prev=-1
        
        self.isPrev=False
        
        self.ans=True
        
        self.check(root)
        
        
        return self.ans
    
    
    def check(self,root):
        
        if root==None:
            return
        
        self.check(root.left)
        
        
        if self.isPrev==False:
            self.isPrev=True
            self.prev=root.val
        else:
            if self.prev>=root.val:
                self.ans=False
                return
            else:
                self.prev=root.val
                
        
        
        self.check(root.right)
        