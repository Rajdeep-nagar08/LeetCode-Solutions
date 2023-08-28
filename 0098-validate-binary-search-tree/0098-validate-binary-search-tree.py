# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        mn=-1e18
        mx=1e18
        ans=True
        
        def find(root,mn,mx):
            nonlocal ans
            if root==None:
                return
            
            find(root.left,mn,root.val)
            
            if root.val<=mn or root.val>=mx:
                ans=False
                return
            
            find(root.right,root.val,mx)
        
        find(root,mn,mx)
        
        return ans
        