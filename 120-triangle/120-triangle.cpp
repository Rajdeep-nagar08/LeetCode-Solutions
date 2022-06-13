int dp[201][201]; // ith row
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        
        memset(dp,-1,sizeof(dp));
        
        if(tr.size()==1)
            return tr[0][0];
        
        return tr[0][0]+ min(find(1,0,tr),find(1,1,tr));
        
    }
    
    int find(int r,int c,vector<vector<int>>&tr){
        
        if(r==tr.size()-1)
            return tr[r][c];
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int mn1=INT_MAX,mn2=INT_MAX;
        
        mn1=min(mn1,tr[r][c]+find(r+1,c,tr));
        
        mn2=min(mn2,tr[r][c]+find(r+1,c+1,tr));
        
        return dp[r][c]=min(mn1,mn2);
    }
};