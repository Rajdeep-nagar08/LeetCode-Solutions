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

// O(n) time , O(n) space
/*
class Solution {
  vector<int>in;
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
      return search(k);
    }
    
  void inorder(TreeNode* root){
    if(!root)
      return;
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
  }
   
  bool search(int k){
    int n=in.size();
    
    int i=0,j=n-1;
    while(i<j){
      int sum=in[i]+in[j];
      if(sum==k)
        return true;
      else if(sum>k)
        j--;
      else
        i++;
    }
    return false;
  }
};
*/
  
/*
O(n*h) time
o(h) space
*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
  
      return find(root,root,k);
    }
     
  bool  find(TreeNode* root,TreeNode* curr,int k){
      if(!curr)
        return false;
      
      return find(root,curr->left,k)||find(root,curr->right,k)||
        search(root,curr,k-curr->val);
    }
  
    bool search(TreeNode* root,TreeNode* curr,int key){
      if(!root)
        return false;
      
      if(root->val==key && root!=curr)
        return true;
      
      if(root->val > key)
        return search(root->left,curr,key);
      
      return search(root->right,curr,key);
    }
};