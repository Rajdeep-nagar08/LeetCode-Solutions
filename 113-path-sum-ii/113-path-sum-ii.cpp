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
          vector<vector<int>>ans;

    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        
        
        vector<int>temp;
        
        int sum=0;
        
        find(root,target,temp,sum);
        
        return ans;
    }
    
    void find(TreeNode* root,int target,vector<int>&temp,int &sum){
        if(!root){
        
            return;
        }
        
       
        
        temp.push_back(root->val);
        sum+=root->val;
        
         if(root->left==nullptr && root->right==nullptr){
         if(sum==target){
                ans.push_back(temp);
            }
        }
        
        find(root->left,target,temp,sum);
        
        find(root->right,target,temp,sum);
        
        temp.pop_back();
        sum-=root->val;
    }
};