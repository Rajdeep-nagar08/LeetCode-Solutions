/*
  
        
        cost of node x= max path sum-min path sum (by keeping x as root)
        
        NOTE: min path sum always= price[x]
        

variation of maximum path sum

But while finding path sum from leaf to leaf, we should include only one leaf

while returning maximum sum of a particular path under the node

we needs to return two type of sum, one is maximum sum while including the 

leaf node and other is maximum sum without the contribution of any leaf node 


*/


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
    
  // code of maximum path sum
        
 // if(!root) return 0;
        
//  int l=max(find(root->left,sum),0);
        
//  int r=max(find(root->right,sum),0);
        
//  sum=max(sum,l+r+root->val);
   
// return max(l,r)+root->val;
        
       lln maxwithleaf=price[node];
        
      lln maxwithoutleaf=0;
                
        for(int x:g[node]){
            if(x!=par){
                
                pair<lln,lln>v1=find(x,node,g,sum,price);
                
                lln withleafcurrPath=v1.first;
                
                lln withoutleafcurrPath=v1.second;
                
                sum=max(sum,maxwithleaf+withoutleafcurrPath);
                
                sum=max(sum,maxwithoutleaf+withleafcurrPath);
                                
                maxwithleaf=max(maxwithleaf,withleafcurrPath+price[node]);
                
          maxwithoutleaf=max(maxwithoutleaf,withoutleafcurrPath+price[node]);
                
            }
            
        }
                
        return {maxwithleaf,maxwithoutleaf}; 
            
    }
};