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
    
    int n;
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        n=nums.size();
        
        return find(0,n-1,nums);
        
    }
    
    TreeNode* find(int i,int j,vector<int>&nums){
        if(i>j)
            return nullptr;
        
        int mid=(i+j)/2;
        
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left=find(i,mid-1,nums);
        
        root->right=find(mid+1,j,nums);
        
        return root;
    }
};