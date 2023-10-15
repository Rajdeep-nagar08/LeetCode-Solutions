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
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,int &rootptr,int start,int end){
        if(start>end) return NULL;
        int inptr=start;
        while(postorder[rootptr]!=inorder[inptr]) inptr++;
        rootptr--;
        
        TreeNode* mynode=new TreeNode(inorder[inptr]);
        mynode->right=fun(inorder,postorder,rootptr,inptr+1,end);
        mynode->left=fun(inorder,postorder,rootptr,start,inptr-1);
        
        
        return mynode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootptr=inorder.size()-1;
        return fun(inorder,postorder,rootptr,0,inorder.size()-1);
    }
};