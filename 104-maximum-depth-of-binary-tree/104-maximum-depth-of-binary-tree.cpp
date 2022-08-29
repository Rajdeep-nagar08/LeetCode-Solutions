class Solution {
public:
    int maxDepth(TreeNode* root) { 
        return depth(root);
        
    }
      int depth(TreeNode* root){
          if(!root)
              return 0;
      int l=depth(root->left);
      int r=depth(root->right);
          
      //    cout<<root->val<<" "<<max(l,r)+1<<endl;
          
       return max(l,r)+1;
          }
};