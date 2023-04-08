/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return node;
        
        vector<Node*>vis(101,NULL);
        
        Node* ans=new Node(node->val);
        
        dfs(node,ans,vis);
        
        return ans;
    }
    
    void dfs(Node* node,Node * ans,vector<Node*>&vis){
        vis[ans->val]=ans;
        
        for(auto x:node->neighbors){
            if(vis[x->val]==NULL){
                Node* newN=new Node(x->val);
                (ans->neighbors).push_back(newN);
                dfs(x,newN,vis);
            }
            else
                (ans->neighbors).push_back(vis[x->val]);
        }
    }
};