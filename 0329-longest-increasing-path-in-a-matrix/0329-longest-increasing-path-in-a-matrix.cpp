int m;
int n;
int dp[201][201];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    n=matrix.size();
    m=matrix[0].size();
        
        int dist=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=dfs(i,j,matrix);
            dist=max(dist,dp[i][j]);
        }
    }    
      return dist;  
    }
    
    
     int dfs(int x,int y,vector<vector<int>>&mt){
        if(dp[x][y]!=-1)
            return dp[x][y];
         
        int mx=1;
         
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
    if(x1 < 0 || y1  <0 || x1 >= n || y1 >= m || mt[x1][y1]<=mt[x][y])
                continue;
           
            mx=max(mx,1+dfs(x1,y1,mt));
            
        }
         return dp[x][y]=mx;
    }

};