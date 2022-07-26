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
        
       int no1=p->val;
        
        int no2=q->val;
        
        
        return find(root,no1,no2);
    }
    
    
    TreeNode* find(TreeNode* root,int no1,int no2){
        if(!root)
            return root;
        
        if(root->val==no1 || root->val==no2)
            return root;
        
        TreeNode* l=find(root->left,no1,no2);
        
        TreeNode* r=find(root->right,no1,no2);
        
        
        if(l && r)
            return root;
        
        if(l)
            return l;
        
        return r;
    }
};