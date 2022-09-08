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
    vector<int>ans;
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        find(root);
        
        return ans;
    }
    
    void find(TreeNode* root){
        if(!root)
            return;
        
        find(root->left);
        
        ans.push_back(root->val);
        
        find(root->right);
        
    }
};