class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        
        sort(inter.begin(),inter.end());
        vector<vector<int>>ans;
        
        int n=inter.size();
        
        ans.push_back(inter[0]);
        int i=1;
        while(i<n){
            int sz=ans.size();
           int l=ans[sz-1][0];
           int r=ans[sz-1][1];
      if((inter[i][0]<=l && inter[i][1]>=l)|| (inter[i][0]>=l && inter[i][1]<=r ) || (inter[i][0]<=r && inter[i][1]>=r)){
          
 ans[sz-1][0]=min(l,inter[i][0]);
 ans[sz-1][1]=max(r,inter[i][1]);
      }
            
            else
                ans.push_back(inter[i]);
            
            
            i++;
        }
          
           
      return ans;
    }
};