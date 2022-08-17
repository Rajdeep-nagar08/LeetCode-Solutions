/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        return lca(root,p,q);
        
    }
    
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        
        if(!root)
            return NULL;
        
        if(root==p || root==q)
            return root;
        
        TreeNode* leftpass= lca(root->left,p,q);
        
        TreeNode* rightpass=lca(root->right,p,q);
        
        
        if(leftpass!=NULL && rightpass!=NULL){
            return root;
        }
        
        if(leftpass==NULL && rightpass!=NULL)
            
             return rightpass;
        
         
     //   if(leftPass!=NULL && rightpass==NULL)
            
             return leftpass;
        
        
        
    }
};