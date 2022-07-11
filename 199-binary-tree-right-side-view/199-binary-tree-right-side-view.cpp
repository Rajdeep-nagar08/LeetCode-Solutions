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
    vector<int> rightSideView(TreeNode* root) {
        
        
        
        vector<int>ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz>0){
              
            TreeNode* r=q.front();
                
                q.pop();
                
                if(sz==1)
                    ans.push_back(r->val);
                
                
                if(r->left)
                    q.push(r->left);
                
                if(r->right)
                    q.push(r->right);
                
                
                sz--;
            }
        }
        
        return ans;
    }
};