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
    bool ans;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        ans=false;
        
        find(root,0,targetSum);
        
        return ans;
        
    }
    
    void find(TreeNode* root,int sum,int target){
        if(!root){
            return;
        }
        
        sum+=root->val;
        
        if(root->left==nullptr && root->right==nullptr && sum==target)
            ans=true;
        
        find(root->left,sum,target);
        
        find(root->right,sum,target);

        
    }
};