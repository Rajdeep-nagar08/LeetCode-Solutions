

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        
        
        q.push(root);
        
        bool prevEmpty=false;
        
        while(!q.empty()){
            
            int sz=q.size();
            
                        
            bool currEmpty=false;

            
            while(sz--){
                

            TreeNode* x=q.front();
            
            q.pop();
                
                
            if(x->left){
                if(prevEmpty || currEmpty)
                    return false;
                
                q.push(x->left);
            }
                else{
                    currEmpty=true;
                }
            
                
            if(x->right){
                if(prevEmpty || currEmpty)
                    return false;
                
                q.push(x->right);
                
            }
                else{
                    currEmpty=true;
                }
            
          }
           
            
            prevEmpty=currEmpty;
            
        
      
    }
        
        return true;
    }
};