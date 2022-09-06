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
    TreeNode* pruneTree(TreeNode* root) {
        
        solve(root);
        
        if(root->val==0 && !root->left && !root->right)
            return nullptr;
        
        return root;
        
        
    }
    
    
    void solve(TreeNode* root){
     
        if(!root)
            return;
        
        int c1=0;
        
        find(root->left,c1);
        
        if(c1==0)
            root->left=nullptr;
        
        c1=0;
        
        find(root->right,c1);
        
        if(c1==0)
            root->right=nullptr;
        
        solve(root->left);
        
        solve(root->right);
        
    }
    
     void find(TreeNode* root,int &sum){
        if(!root)
            return;
        
        sum+=root->val;
         
         find(root->left,sum);
         
         find(root->right,sum);
        
        
    }
    
   
};