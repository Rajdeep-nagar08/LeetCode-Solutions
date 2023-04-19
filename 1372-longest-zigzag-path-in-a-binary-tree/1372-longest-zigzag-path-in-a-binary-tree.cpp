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

/* O(n*n)  Shows TLE

class Solution {
  
public:
    int longestZigZag(TreeNode* root) {
        if(!root)
          return 0;
      int l=find(root->left,1);
      int r=find(root->right,0);
      
      int l1=longestZigZag(root->left);
      int l2=longestZigZag(root->right);
      
      return max(max(max(l,r),l1),l2);
      
    }
    
  int find(TreeNode* root,int d){
    if(!root)
      return 0;
    
     if(d==1)
       return 1+find(root->right,0);
    else
      return 1+find(root->left,1);
  }
};

*/

class Solution {
  map<TreeNode*,int>mp;
  map<TreeNode*,int>temp;
public:
    int longestZigZag(TreeNode* root) {
        if(!root)
          return 0;
    /*  
      if(mp.count(root)==1)
        return mp[root];
      int l,r;
      
      if(temp.count(root->left)==1)
        l=temp[root->left];
      else
        l=find(root->left,1);
      
      temp[root->left]=l;
        
      if(temp.count(root->right)==1)
        r=temp[root->right];
      else
        r=find(root->right,0);
      
      temp[root->right]=r;
  */
      int l=find(root->left,1);
      int  r=find(root->right,0);

      
      int l1=longestZigZag(root->left);
      int l2=longestZigZag(root->right);
      
      return mp[root]= max(max(max(l,r),l1),l2);
      
    }
    
  int find(TreeNode* root,int d){
    if(!root)
      return 0;
    
    if(temp.count(root)==1)
      return temp[root];
    
     if(d==1)
       return temp[root]=1+find(root->right,0);
    else
      return temp[root]=1+find(root->left,1);
  }
};
