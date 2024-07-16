/*
class Solution {
  unordered_map<int,vector<pair<int,string>>>mp;
public:
    string getDirections(TreeNode* root, int start, int end) {
        
      queue<TreeNode*>q;
      q.push(root);
      
      while(!q.empty()){
        int sz=q.size();
        while(sz--){
          TreeNode* node=q.front();
          q.pop();
          
          if(node->left){
            q.push(node->left);
            mp[node->val].push_back({node->left->val,"L"});
            mp[node->left->val].push_back({node->val,"U"});
          }
                    if(node->right){
            q.push(node->right);
            mp[node->val].push_back({node->right->val,"R"});
            mp[node->right->val].push_back({node->val,"U"});
          }

        }
      }
      
      
      int v=mp.size();
      return BFS(start,end,v);
    }
  
  
string BFS(int src, int dest, int v)
{
  
    list<int> queue;
   vector<pair<int,string>>dist(v+1);
    bool visited[v+1];
 

    for (int i = 1; i<=v; i++) {
        visited[i] = false;
        dist[i] = {INT_MAX,""};
      
    }
 
    visited[src] = true;
    dist[src] = {0,""};
    queue.push_back(src);
 

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for(auto it:mp[u]){
            if (visited[it.first] == false) {
                visited[it.first] = true;
                 string str= dist[u].second;
                 str=str+it.second;
                 dist[it.first] = make_pair(dist[u].first + 1,str);
                queue.push_back(it.first);
 
                if (it.first == dest)
                    return dist[dest].second;
            }
        }
    }
      
 
     
  return "";
  
    }
};

*/


class Solution {
public:
    string getDirections(TreeNode* root, int start, int end) {
      
      
      TreeNode* lca= getlca(root,start,end);
      
      string s="",e="";
      
      find(lca,s,start);
        
      find(lca,e,end);
      
      for(char &c:s)
        c='U';
      
      return s+e;
    }
  
    TreeNode* getlca(TreeNode* root,int n1,int n2){
      if(!root)
        return root;
      
      if(root->val==n1 || root->val==n2)
        return root;
      
      TreeNode* l= getlca(root->left,n1,n2);
      TreeNode* r= getlca(root->right,n1,n2);
      
      if(l && r)
        return root;
      
      else if(l)
        return l;
      
        return r;
    }
  
  bool find(TreeNode* root,string& str,int no){
    
    if(!root)
      return false;
    
    if(root->val==no){
      return true;
    }
    
    str+="L";
    bool l=find(root->left,str,no);
    if(l==true)
      return true;
    str.pop_back();
    
    
    str+="R";
    bool r=find(root->right,str,no);
    if(r==true)
      return true;
    str.pop_back();
  
    
    return false;
  }
  
};
        