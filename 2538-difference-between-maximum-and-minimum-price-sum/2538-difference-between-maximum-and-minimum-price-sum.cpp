
#define lln long long int

class Solution {
public:
    
    
    
    long long maxOutput(int n, vector<vector<int>>& edg, vector<int>& price) {
    
        vector<int>g[n];
        
        for(int i=0;i<n-1;i++){
            g[edg[i][0]].push_back(edg[i][1]);
            g[edg[i][1]].push_back(edg[i][0]);
        }
      
        
        lln sum=-1e18;
        
         find(0,-1,g,sum,price);
        
        if(sum==-1e18)
            return 0;
        
        return sum;
    }
    
    pair<lln,lln> find(int node,int par,vector<int>g[],lln &sum,vector<int>&price){
    
 // if(!root) return 0;
        
//  int l=max(find(root->left,sum),0);
        
//  int r=max(find(root->right,sum),0);
        
//  sum=max(sum,l+r+root->val);
   
// return max(l,r)+root->val;
        
       lln withleaf=price[node];
        
      lln withoutleaf=0;
                
        for(int x:g[node]){
            if(x!=par){
                
                pair<lln,lln>v1=find(x,node,g,sum,price);
                
                sum=max({sum,withleaf+v1.second,withoutleaf+v1.first});
                                
                withleaf=max(withleaf,v1.first+price[node]);
                
                withoutleaf=max(withoutleaf,v1.second+price[node]);
                
            }
            
        }
                
        return {withleaf,withoutleaf}; 
            
    }
};