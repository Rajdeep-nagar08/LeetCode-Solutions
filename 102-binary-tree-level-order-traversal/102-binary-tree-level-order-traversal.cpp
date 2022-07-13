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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
                    vector<int>temp;

        
        while(!q.empty()){
            int sz=q.size();
            
            
            while(sz--){
                TreeNode* r=q.front();
                q.pop();
                temp.push_back(r->val);
                
                if(r->left){
                    q.push(r->left);
                }
                if(r->right){
                    q.push(r->right);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};