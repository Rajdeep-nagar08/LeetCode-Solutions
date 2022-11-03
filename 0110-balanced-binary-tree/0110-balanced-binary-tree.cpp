/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    
     int maxDepth(TreeNode* root) {
          if(root==NULL)
              return 0;
         
        int leftheight=maxDepth(root->left);
        int rightheight=maxDepth(root->right);
        int height=max(leftheight,rightheight)+1;
        return height;
    }
    
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        if(abs((maxDepth(root->left)-maxDepth(root->right)))>1){
         return false;
        }
        
        bool l=isBalanced(root->left);
        
        bool r=isBalanced(root->right);
        
        return l && r;
    }
};