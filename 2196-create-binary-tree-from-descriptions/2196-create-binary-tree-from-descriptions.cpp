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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        unordered_map<int, TreeNode*>mp;
        unordered_map<int,int>deg;
        for(auto it: des){
            int p=it[0];
            int c=it[1];
            int pos=it[2];
            if(!mp.count(p))
                mp[p]=new TreeNode(p);
            
             if(pos==1){
                 if(mp.count(c))
                     mp[p]->left=mp[c];
                 else{
                    mp[c]=new TreeNode(c); 
                    mp[p]->left=mp[c];
                 }
             }
                else{
                    if(mp.count(c))
                        mp[p]->right=mp[c];
                    else{
                    mp[c]=new TreeNode(c);    
                    mp[p]->right=mp[c];
                    }
                }
            deg[c]++;
        }
        
        
    
        for(auto it:mp)
            if(deg.count(it.first)==0)
                return it.second;
        
        return new TreeNode(0);
    }
};