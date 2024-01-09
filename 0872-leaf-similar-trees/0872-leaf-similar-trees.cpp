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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      string s1="";
       make(root1,s1);
      
       string s2="";
       make(root2,s2);
      
      if(s1==s2)
        return true;
      
      return false;
    }
  
      void make(TreeNode* root,string &s){
        if(!root)
          return;
        
        if(root->left==nullptr && root->right==nullptr){
          s+=to_string(root->val);
          s+=",";
        }
        
        make(root->left,s);
        make(root->right,s);   
    }
};