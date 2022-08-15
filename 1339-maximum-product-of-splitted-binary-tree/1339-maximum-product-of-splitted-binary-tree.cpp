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
    
    const int MOD = 1e9 + 7;
    
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        
        int sum = root->val + l + r;
        return sum;
    }
    
    long long res = 0;
    int total = 0;
    
    int getSum(TreeNode* root) {
        if(root == NULL) return 0;
        long long l = getSum(root->left);
        long long r = getSum(root->right);
                
        long long res1 = (total - l) * l;
        long long res2 = (total - r) * r;
        
        // cout << res1 << " " << res2 << endl;
        
        res = max({res, res1, res2});
        
        return root->val + l + r;
    }
    
    int maxProduct(TreeNode* root) {
        total = helper(root);
        // cout << total << endl;
        getSum(root);
        res %= MOD;
        return res;
    }
};