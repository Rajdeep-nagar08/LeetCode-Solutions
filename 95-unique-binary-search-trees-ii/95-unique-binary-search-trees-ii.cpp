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
    vector<TreeNode*> generateTrees(int n) {
        
        
        return find(1,n);
    }
    
    vector<TreeNode*> find(int i,int j){
        
        vector<TreeNode*>ans;

        if(i>j){
            ans.push_back(nullptr);
            return ans;
        }
        
        
        for(int k=i;k<=j;k++){
            vector<TreeNode*>l=find(i,k-1);
            
            vector<TreeNode*>r=find(k+1,j);
            
            for(int k1=0;k1<l.size();k1++){
                for(int k2=0;k2<r.size();k2++){
                    TreeNode* root=new TreeNode(k);
                    
                    root->left=l[k1];
                    root->right=r[k2];
                    
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};