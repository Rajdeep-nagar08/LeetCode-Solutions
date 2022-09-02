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
    vector<double> averageOfLevels(TreeNode* root) {
                
        vector<double>ans;
        queue<TreeNode*>q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int sz=(int)q.size();
            
            double sum=0.00000;
            double count=0.00000;
            while(sz--)
            {
            
            TreeNode* node=q.front();
            q.pop();
                sum+=node->val;
                count++;
            if(node->left )
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
            }
            if(count!=0.00000)
            ans.push_back(sum/count);
            
        }
        return ans;
        
    }
};