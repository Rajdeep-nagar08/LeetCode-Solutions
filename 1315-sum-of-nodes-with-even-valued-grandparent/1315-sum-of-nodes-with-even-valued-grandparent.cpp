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
    int sumEvenGrandparent(TreeNode* root) {
      
        int ans=0;
        
        queue<pair<TreeNode*,pair<int,int>>>q;  // node, {parent,grandparent}
        
        q.push({root,{-1,-1}});
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                pair<TreeNode*,pair<int,int>>p=q.front();
                q.pop();
                TreeNode* x=p.first;
                int par=p.second.first;
                int garPar=p.second.second;
                
                if(garPar!=-1 && garPar%2==0)
                    ans+=x->val;
                
                if(x->left){
                    q.push({x->left,{x->val,par}});
                }
                if(x->right){
                   q.push({x->right,{x->val,par}});

                }
            }
        }
        
        return ans;
    }
};