/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
                vector<vector<int>>ans;
        vector<int>temp;
        queue<Node*>q;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* node=q.front();
                q.pop();
                temp.push_back(node->val);
                for(Node* x:node->children){
                    q.push(x);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
       return ans; 
    }
};