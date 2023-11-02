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
    int count=0;
public:
    int averageOfSubtree(TreeNode* root) {
        
        find(root);
        
        return count;
    }
    
    void find(TreeNode* root){
        if(!root)
            return;
        
        find(root->left);
        
        int c1=0,c2=0;
        int s1=0,s2=0;
        
        find1(root->left,c1,s1);
        find1(root->right,c2,s2);
    
            int avg=(s1+s2+root->val)/(c1+c2+1);
            
            if(avg==root->val)
                count++;
        
        find(root->right);
    }
    
    void find1(TreeNode* root,int &c,int &sum){
        if(!root)
            return;
        
        sum+=root->val;
        c++;
        
        find1(root->left,c,sum);
        find1(root->right,c,sum);

        
    }
    
    
};