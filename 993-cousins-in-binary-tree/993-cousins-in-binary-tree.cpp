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
    
    int p1,p2;
    
    int h1,h2;
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        height(root,x,y,-1,0); 
    
      if((h1==h2) && (p1!=p2))
          return true;
        
        return false;
        
    }
    
    void height(TreeNode* root,int x,int y,int par,int ht){
        
        if(!root)
            return;
        
        height(root->left,x,y,root->val,ht+1);
        
        height(root->right,x,y,root->val,ht+1);        
        
        if(root->val==x){
            p1=par;
            h1=ht;
        }
        
        
        if(root->val==y){
            p2=par;
            h2=ht;
        }
                
    }
};