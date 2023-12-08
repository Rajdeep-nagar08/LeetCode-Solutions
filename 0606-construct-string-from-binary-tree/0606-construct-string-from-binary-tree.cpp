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
    
    string ans;
    
    string tree2str(TreeNode* root) {
        
        find(root);
        
        return ans;
    }
    
    void find(TreeNode* root){
        
        if(!root)
            return;
        
        ans+=to_string(root->val);
        
        if(root->left==nullptr && root->right==nullptr)
            return;
        
        ans+="(";
        
        find(root->left);
        
        ans+=")";
        
        if(root->right){
        
        ans+="(";
        
        find(root->right);
        
        ans+=")";
            
        }
        
        
    }
};