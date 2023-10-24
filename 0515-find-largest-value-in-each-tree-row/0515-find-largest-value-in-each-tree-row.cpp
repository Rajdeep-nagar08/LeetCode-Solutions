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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
       while(!q.empty()){
           int sz=q.size();
           int mx=q.front()->val;
           while(sz--){
      TreeNode* node=q.front();
      q.pop();
      mx=max(mx,node->val);
        if(node->left)
         q.push(node->left);
         if(node->right)
             q.push(node->right);
               }
           v.push_back(mx);
           }
        return v;
    }
};