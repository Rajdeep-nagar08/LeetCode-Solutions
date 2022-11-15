/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count=0;
void preorder(struct TreeNode *root) 
{
    
    if(root!=0)
  {
     count++;
    preorder(root->left);
    preorder(root->right);
  }
}

    
int countNodes(struct TreeNode* root){
    count=0;
    preorder(root);
    
    return(count);
}