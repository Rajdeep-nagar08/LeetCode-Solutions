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

#define lln long long int

class Solution {
public:
    bool first=false;
    int prev;
    bool isValidBST(TreeNode* root) {
       
        bool ans=true;
        
        lln l=-1e15;
        
        lln r=1e15;
        
        find(root,ans,l,r);
        
        return ans;
    }
    

    void find(TreeNode* root,bool &ans,lln mn,lln mx){
        if(!root)
            return;
        
     find(root->left,ans,mn,root->val);
     
     if(root->val<=mn || root->val >=mx){
         ans=false;
         return;
     }
        
     find(root->right,ans,root->val,mx);
        
    }
};