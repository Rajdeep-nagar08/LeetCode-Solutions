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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
      queue<pair<TreeNode*,int>>q;
      map<int,vector<pair<int,int>>>mp;  /* used to store all nodes of particular          height,and level*/
      q.push({root,0});   // node, height  (h:- .... -2,-1,0,1,2.....)
      int level=0;
      while(!q.empty()){
        int sz=q.size();
      
          while(sz--){
        TreeNode* node=q.front().first;
        int h=q.front().second;
        q.pop();
        mp[h].push_back({level,node->val});
        if(node->left)
          q.push({node->left,h-1});
        if(node->right)
          q.push({node->right,h+1});
      }
         level++;
      }
      
      vector<vector<int>>ans(mp.size());
      int i=0;
      for(auto x:mp){
        sort(x.second.begin(),x.second.end());
        for(auto x1:x.second)
          ans[i].push_back(x1.second);
        
        i++;
      }
      return ans;
    }
};