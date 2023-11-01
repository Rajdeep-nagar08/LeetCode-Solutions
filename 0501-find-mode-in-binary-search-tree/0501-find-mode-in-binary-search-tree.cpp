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
    void find(TreeNode* root,vector<int>& mode,int &c_freq,int &mx,TreeNode** temp){
        
        if(root==nullptr)
            return;
        find(root->left,mode,c_freq,mx,temp);
       
        
        
      if(*temp!=nullptr && (*temp)->val==root->val)
    c_freq++;
        else 
            c_freq=1;
        if(c_freq>mx)
            {
            mode.clear();
            mode.push_back(root->val);
            mx=c_freq;
            }
      else if(c_freq==mx)
            mode.push_back(root->val);
        *temp=root;
        find(root->right,mode,c_freq,mx,temp);
        }
               
            
            
            
       
       
        

public:
    vector<int> findMode(TreeNode* root) {
        vector<int>mode;
        int c_freq=0;
        int mx=INT_MIN;
        
        TreeNode* temp=NULL;
        find(root,mode,c_freq,mx,&temp);
        return mode;
       
    }
};