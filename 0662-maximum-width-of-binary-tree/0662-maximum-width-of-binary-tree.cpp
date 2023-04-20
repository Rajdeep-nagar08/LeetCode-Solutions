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
    #define lln long long int
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        lln count=INT_MIN;
        q.push({root,0});
            while(!q.empty()){
                int sz=q.size();
                lln l=q.front().second;
                lln r=0;
                for(int i=0;i<sz;i++){
                     TreeNode* temp=q.front().first;
                     r=q.front().second;
                       q.pop();
                  if(temp->left)
                      q.push({temp->left,2*r+1});
                    if(temp->right)
                        q.push({temp->right,2*r+2});
                }
                count=max(count,(r-l+1));
            }
        return count;
    }
};