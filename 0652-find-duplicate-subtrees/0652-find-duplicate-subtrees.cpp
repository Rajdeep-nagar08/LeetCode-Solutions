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
    
    unordered_map<string,int>mp;


vector<TreeNode*>ans;
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        mp.clear();
        
        postorder(root);
        
        return ans;
    }
    
    
    string postorder(TreeNode* root){
        
        if(!root)
            return "x";
        
        string l=postorder(root->left);
        
        string r=postorder(root->right);
        
        string temp=l;
        
        temp+=" ";
                        
        temp+=to_string(root->val);
        
        temp+=r;
        
        temp+=" ";
        

        if(temp.size()>0 && (mp[temp]==1) && root){
            ans.push_back(root);
        }
        

     //   cout<<temp<<endl;
        
        if(temp.size()>0)
       mp[temp]++;
        
        return temp;
        
        
    }
    
    
    
};