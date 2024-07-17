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
  unordered_set<int>st;
  vector<TreeNode*>v;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        
      if(!root)
        return {};
      
        for(auto x:del)
          st.insert(x);
       
      delN(root);
      
      if(root)
        v.push_back(root);
      
      return v;  
     }
  
    void delN(TreeNode* &root ){
      
      if(!root)
        return;
  /*
        delN(root->left);
        delN(root->right);
        */
      if(root){
        delN(root->left);
        delN(root->right);
      
      if(st.find(root->val)!=st.end()){
        if(root->left)
          v.push_back(root->left);
        if(root->right)
          v.push_back(root->right);
        
         root=nullptr;
        delete(root);
      }
      }
   
      
    }
};