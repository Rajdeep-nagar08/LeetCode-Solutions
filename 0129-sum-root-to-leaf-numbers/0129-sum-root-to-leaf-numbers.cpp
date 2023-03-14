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
  int ans;
public:
  
    int sumNumbers(TreeNode* root) {
        ans=0;
       find(root,0);
      return ans;
    }
  
   void find(TreeNode* root,int temp_sum){
      if(!root)
        return;
     
      temp_sum=temp_sum*10 + root->val;
      
      if(root->left==NULL && root->right==NULL)
        ans= ans+temp_sum;
      
      find(root->left,temp_sum);
      find(root->right,temp_sum);
      
    }
};