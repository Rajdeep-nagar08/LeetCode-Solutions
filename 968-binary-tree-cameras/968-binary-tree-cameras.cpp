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

for each node we have choices either to install camera at this node or not

so we can think about dp

dp[node][parent]= min no of cameras needs for subtree of node if we have two choices for this node (itself), consediring whether parent of u has camera or not


*/
class Solution {
public:
    #define NO_CAMERA       0
    #define HAS_CAMERA      2
    #define NOT_NEEDED      1
    int ans = 0;
    int dfs(TreeNode *root) {
        if (!root) return NOT_NEEDED;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == NO_CAMERA || r == NO_CAMERA) {
            ans++;
            return HAS_CAMERA;
        } else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        } else {
            return NO_CAMERA;
        }
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == NO_CAMERA) ans++;
        return ans;
    }
};