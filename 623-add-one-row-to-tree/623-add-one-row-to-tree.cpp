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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode* l=new TreeNode(val);
            
            l->left=root;
            
            return l;
            
        }
        
        return find(root,val,depth,2);
        
    }
    
    TreeNode* find(TreeNode* root,int val,int depth,int d){
        if(!root)
            return root;
        
        if(d==depth){
            
            TreeNode* l=new TreeNode(val);
            
            l->left=root->left;
            
            TreeNode* r=new TreeNode(val);
            
            r->right=root->right;
            
            root->left=l;
            
            root->right=r;

        }
        
        find(root->left,val,depth,d+1);
        
        find(root->right,val,depth,d+1);
        
        
        return root;
        
    }
};