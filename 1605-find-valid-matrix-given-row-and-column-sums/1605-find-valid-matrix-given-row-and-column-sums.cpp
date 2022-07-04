class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
     
        int n=rs.size();
        
        int m=cs.size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            
        for(int i=0;i<n;i++){
            
            int mn=min(rs[i],cs[j]);
                ans[i][j]=mn;
                rs[i]=rs[i]-mn;
                cs[j]=cs[j]-mn;
            
            
            
        }
            
    }
    
        return ans;
        
    }
};