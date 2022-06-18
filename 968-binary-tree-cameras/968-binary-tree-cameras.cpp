
/*

for each node we have choices either to install camera at this node or not

so we can think about dp

dp[node][parent]= min no of cameras needs for subtree of node if we have two choices for this node (itself), consediring whether parent of node has camera or not

*/


/*

Recursive ---- TLEEEEEEEEEEEEE

class Solution {
public:
    
    int minCameraCover(TreeNode* root) {
       
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;

        // giving camera to root
        
        c1=min(c1,1+find(root->left,1)+find(root->right,1));
        
        // not giving camera to root, then there must be atleast one camera on its any child
        
        if(root->left && root->right){
        
           c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1)+find(root->right,0));
          
            c3= min(c3,1+ find(root->left,0)+ find(root->right->left,1)+find(root->right->right,1));
            
            
        }
        
        else if(root->left){
    c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1));
          
            
        }
        
        else if(root->right){
    c2= min(c2,1+find(root->right->left,1)+find(root->right->right,1));
             
        }
         
        return min({c1,c2,c3});
        
    }
    
    
   int find(TreeNode* root,int par){
        
        if(!root)
            return 0;
        
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
        
        if(par==1){
            
         // either camera to this root or not give camera
        
            c1=min(c1,1+find(root->left,1)+find(root->right,1));
               
           c2=min(c2,find(root->left,0)+find(root->right,0));

           
        }
        
        else{
            
           // giving camera to root
        
        c1=min(c1,1+find(root->left,1)+find(root->right,1));
        
        // not giving camera to root, then there must be atleast one camera on its any child
        
        if(root->left && root->right){
        // giving to left not to right
  c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1)+
                 find(root->right,0));
        // not giving to right, giving to left  
 c3= min(c3,1+ find(root->left,0)+
                 find(root->right->left,1)+find(root->right->right,1));
              
        }
            
        else if(root->left){
    c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1));
          
            
        }
            
        else if(root->right){
    c2= min(c2,1+find(root->right->left,1)+find(root->right->right,1));
             
        }
    }
        
    return min({c1,c2,c3});
        
}

};

*/

unordered_map<TreeNode*,unordered_map<int,int>>mp;

class Solution {
public:
    
    int minCameraCover(TreeNode* root) {
       
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;

        // giving camera to root
        
        c1=min(c1,1+find(root->left,1)+find(root->right,1));
        
        // not giving camera to root, then there must be atleast one camera on its any child
        
        if(root->left && root->right){
        
           c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1)+find(root->right,0));
          
            c3= min(c3,1+ find(root->left,0)+ find(root->right->left,1)+find(root->right->right,1));
            
            
        }
        
        else if(root->left){
    c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1));
          
            
        }
        
        else if(root->right){
    c2= min(c2,1+find(root->right->left,1)+find(root->right->right,1));
             
        }
         
        return min({c1,c2,c3});
        
    }
    
    
   int find(TreeNode* root,int par){
        
        if(!root)
            return 0;
       
       if(mp[root].count(par))
           return mp[root][par];
        
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
        
        if(par==1){
            
         // either camera to this root or not give camera
        
            c1=min(c1,1+find(root->left,1)+find(root->right,1));
               
           c2=min(c2,find(root->left,0)+find(root->right,0));

           
        }
        
        else{
            
           // giving camera to root
        
        c1=min(c1,1+find(root->left,1)+find(root->right,1));
        
        // not giving camera to root, then there must be atleast one camera on its any child
        
        if(root->left && root->right){
        // giving to left not to right
  c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1)+
                 find(root->right,0));
        // not giving to right, giving to left  
 c3= min(c3,1+ find(root->left,0)+
                 find(root->right->left,1)+find(root->right->right,1));
              
        }
            
        else if(root->left){
    c2= min(c2,1+ find(root->left->left,1)+find(root->left->right,1));
          
            
        }
            
        else if(root->right){
    c2= min(c2,1+find(root->right->left,1)+find(root->right->right,1));
             
        }
    }
        
    return mp[root][par]= min({c1,c2,c3});
        
}

};

