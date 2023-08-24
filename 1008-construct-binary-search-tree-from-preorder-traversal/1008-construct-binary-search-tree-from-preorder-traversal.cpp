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
          int i=0;

    TreeNode* bstFromPreorder(vector<int>& pre) {
      
      int n=pre.size();
      return find(pre[0],n,pre,INT_MAX,INT_MIN);
    }
  
    TreeNode* find(int key,int n,vector<int>&pre,int max,int min){
      
      if(i>=n)
         return nullptr;
        
      TreeNode *root=nullptr;
        
      if(key>min && key<max)
      {
          root=new TreeNode(key);
      
      i++;
        
      if(i<n)
        root->left=find(pre[i],n,pre,key,min);
      
      if(i<n)
        root->right=find(pre[i],n,pre,max,key);
      
      }
      
      return root;
    }
};
