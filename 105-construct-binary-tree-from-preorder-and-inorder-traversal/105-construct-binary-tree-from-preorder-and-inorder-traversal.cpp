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
     int i=0;

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        /*
preorder:-
 root,left,right
inorder:-
left ,root,right
*/
      return build(pre,in,0,pre.size()-1);
    }
  
     TreeNode* build(vector<int>&pre,vector<int>&in,int start,int end){
    
       if(start>end)
         return nullptr;
       
        int curr=pre[i];
        i++;
        TreeNode* root=new TreeNode(curr);
       
       if(start==end)
         return root;
       
       int pos= search(in,curr,start,end);
       root->left=build(pre,in,start,pos-1);
       root->right=build(pre,in,pos+1,end);
       
       return root;
     }
  
      int search(vector<int>&in,int curr,int start,int end){
        int j;
        for(j=start;j<=end;j++){
          if(in[j]==curr)
            break;
        }
        return j;
      }
};

