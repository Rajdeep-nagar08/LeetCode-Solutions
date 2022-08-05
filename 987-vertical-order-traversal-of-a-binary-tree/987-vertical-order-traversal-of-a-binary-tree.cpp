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
    
    void fillMap(map<int, vector<int>> &mp, TreeNode* root) {
        if(root == NULL) return;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(q.empty() == false) {
            int s = q.size();
            vector<pair<int,int>> temp;
            for(int i = 0; i < s; i++) {
                auto curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                int val = curr.second;
                temp.push_back({val, node->val});
                // cout << node->val << " ";

                if(node->left) {
                    q.push({node->left, val - 1});
                }
                if(node->right) {
                    q.push({node->right, val + 1});
                }            
            }
            sort(temp.begin(), temp.end());
            for(auto it: temp) {
                mp[it.first].push_back(it.second);
            }
        }   
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        fillMap(mp, root);
        vector<vector<int>> ans;
        for(auto it: mp) {
            vector<int> temp;
            for(auto i: it.second) {
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};