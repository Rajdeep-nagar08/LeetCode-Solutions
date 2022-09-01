/*


all value from node------X are smaller than X


*/



class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,root->val});
        
        int count=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
            TreeNode* node=q.front().first;
                
            int mxTill=q.front().second;
                
            q.pop();
                
                
            cout<<node->val<<" "<<mxTill<<endl;

            if(mxTill<=node->val){
                count++;
            }
                
             if(node->left){
                 int mxTill1=max(mxTill,node->left->val);
                 q.push({node->left,mxTill1});
             }
                
            if(node->right){
                 int mxTill2=max(mxTill,node->right->val);
                 q.push({node->right,mxTill2});
             }
                
          }
            
        }
        
        return count;
        
    }
};