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
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in)
    {
        
        return help(pre,in,0,pre.size()-1);
        

        
    }
    
    
    int k=0;
    
    TreeNode* help(vector<int>& pre, vector<int>& in,int start,int end){
    
        if(start>end)
            return NULL;
    
     // cout<<start<<"="<<end<<endl;
     int val=pre[k];
     TreeNode* root=new TreeNode(val);
     k++;
   
     int idx= find(start,end,val,in,pre);
        // cout<<idx<<" "<<val<<endl;
     root->left=help(pre,in,start,idx-1);
     root->right=help(pre,in,idx+1,end);
     return root;

   }
    
    int find(int i, int j, int x, vector<int>&in, vector<int>&pre){
     int idx;
     for(int t=i;t<=j;t++){
         if(in[t]==x){
             idx=t;
             break;
         }
    }
        return idx;
        
    }


    
};