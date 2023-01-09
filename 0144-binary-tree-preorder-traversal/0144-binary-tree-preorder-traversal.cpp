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
  vector<int>pre;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
          return pre;
      find(root);
      return pre;
    }
  
     void find(TreeNode* root){
       if(!root)
         return;
       
       pre.push_back(root->val);
       find(root->left);
       find(root->right);
     }
};