
// for each level of a tree, precalculate its largest and second largest depth

// for each node, calculate its level and depth of subtree under it


class Solution {
public:
    
    unordered_map<int,int>ht;
 
    unordered_map<int,int>lvl;
   
    vector<int> treeQueries(TreeNode* root, vector<int>& qr) {
    
        
        dfs(root);
        
        unordered_map<int,vector<int>>mp;  
        
        // lvl => {depth under all nodes of that level}
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
                                             
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
            TreeNode* node=q.front().first;
            
            int l=q.front().second;
            
            q.pop();
            
            lvl[node->val]=l;
                
            mp[l].push_back(ht[node->val]);
            
            if(node->left){
                q.push({node->left,l+1});
            }
            
            if(node->right){
                q.push({node->right,l+1});
            }
                
        }
                        
    }
        
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }

        
        int n=qr.size();
        
        vector<int>ans;
        
        int node,l,h,idx,prev;
        
        for(int i=0;i<n;i++){
            
            node=qr[i];
            
            l=lvl[node];
            
            h=ht[node];
            
            idx=lower_bound(mp[l].begin(),mp[l].end(),h)-mp[l].begin();
                        
            prev=idx-1;
            
            if(idx!=mp[l].size()-1){
                ans.push_back(l+=mp[l][mp[l].size()-1]);
            }
            
            else if(prev>=0){
                ans.push_back(l+mp[l][prev]);
            }
            else{
                ans.push_back(l-1);
            }
            
           
        }
        
       return ans;
        
    }
    
    int dfs(TreeNode* root){
        if(!root)
            return -1;
        
        int l=dfs(root->left);
        
        int r=dfs(root->right);
        
        return ht[root->val]=1+max(l,r);
        
    }
};