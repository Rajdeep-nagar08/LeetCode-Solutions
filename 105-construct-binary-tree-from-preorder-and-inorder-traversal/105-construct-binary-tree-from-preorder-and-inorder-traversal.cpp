/*

class Solution {
public:
     int i=0;

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    
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


*/

class Solution {
public:
    TreeNode*func(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart, int inEnd, unordered_map<int,int>&in)
    {
        
        if(preStart>preEnd || inStart>inEnd)
        {
            return NULL;
            
        }
        
        TreeNode*root= new TreeNode(preorder[preStart]);
        
        int inRoot= in[root->val];
        
        int left=inRoot-inStart;
        
        root->left=func(preorder,preStart+1,preStart+left,inorder,inStart,inRoot-1,in);
        
        root->right=func(preorder,preStart +left+1,preEnd,inorder,inRoot+1,inEnd,in);
        
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
           unordered_map<int,int>in;
        
        for(int i=0;i<inorder.size();i++)
        {
            
            in[inorder[i]]=i;
            
            
        }
        
    TreeNode*root= func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,in);
        
        return root;
        
    }
};