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
   int mx=INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        
      find(root);
        return mx;
    }
    void find(TreeNode* root){
        if(!root)
            return ;
      
        get(root,root->left);
        get(root,root->right);
        find(root->left);
        find(root->right);
        }
  void get(TreeNode* anc,TreeNode* ch){
      
        if(!ch)
            return ;
      
 mx=max(mx,abs(anc->val-ch->val));
        get(anc,ch->left);
        get(anc,ch->right);
        }
        
};