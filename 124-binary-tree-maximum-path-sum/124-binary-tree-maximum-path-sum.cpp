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
    int maxPathSum(TreeNode* root) {
        
        
        int sum=INT_MIN;
        
         find(root,sum);
        
        return sum;
    }
    
    int find(TreeNode* root,int &sum){
        if(!root)
            return 0;
        
        int l=max(find(root->left,sum),0);
        
        int r=max(find(root->right,sum),0);
        
        sum=max(sum,l+r+root->val);
        
        return max(l,r)+root->val;
    }
};