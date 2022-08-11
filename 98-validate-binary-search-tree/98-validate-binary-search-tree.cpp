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
    bool first=false;
    int prev;
    bool isValidBST(TreeNode* root) {
       
        bool ans=true;
        
        find(root,ans);
        
        return ans;
    }
    
    void find(TreeNode* root,bool &ans){
        if(!root)
            return;
        
      find(root->left,ans);
        
       if(first){
           if(root->val<=prev){
               ans=false;
               return;
           }
           prev=root->val;
       }
        
      else{
          first=true;
          prev=root->val;
      }
        
     find(root->right,ans);
        
    }
};