
class Solution {
public:
    int count=0;
    
    unordered_map<int,int>mp;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
     
        /*
        
        frequency of atmost one number is odd
        
        */
        
        find(root);
        
        return count;
        
    }
    
    void find(TreeNode* root){
        if(!root){
            
            return;
        }
        
        mp[root->val]++;
        
        if(root->left==nullptr && root->right==nullptr){
             int odd=0;
            
            for(auto it:mp){
                if(it.second%2)
                    odd++;
            }
            
            if(odd<=1)
                count++;
        }
        
        find(root->left);
        
        find(root->right);
        
        mp[root->val]--;
        
    }
};