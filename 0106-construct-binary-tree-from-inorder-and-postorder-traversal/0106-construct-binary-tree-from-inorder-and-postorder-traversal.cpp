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

/*
inorder: left,root,right
postorder: left,right,root
*/

class Solution {
  int k;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      k=postorder.size()-1;

      return buildT(inorder,postorder,0,postorder.size()-1);
    }
     
    TreeNode* buildT(vector<int>&inorder,vector<int>&postorder,int start,int end){
  
      if(start>end)
        return nullptr;
      
      int curr=postorder[k];
       k--;
      
      TreeNode* root=new TreeNode(curr);
      if(start==end)
        return root;
     int pos=search(inorder,start,end,curr);
      root->right=buildT(inorder,postorder,pos+1,end);

      root->left=buildT(inorder,postorder,start,pos-1);

      return root;
    }
  int search(vector<int>& inorder,int start,int end,int key){
    for(int i=start;i<=end;i++){
      if(inorder[i]==key)
        return i;
    }
      return -1;
  }
     
};


