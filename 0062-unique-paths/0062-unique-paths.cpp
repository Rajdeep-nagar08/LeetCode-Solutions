
 /*
        robot can either move down or right 
        
        dp[i][j] = no of moves robot takes to move from (i,j) to (n-1 , m-1)
        
        Ans= dp[0][0]
        
 */
int dp[101][101];
int dx[2]={1,0};
int dy[2]={0,1};
class Solution {
public:
    int uniquePaths(int n,int m) {
     
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,n,m);
        
    }
    
    
      int find(int i,int j,int n,int m){
          if(i==n-1 && j==m-1){
              return 1;
          }
          
          if(i>=n || j>=m)
              return 0;
          
          if(dp[i][j]!=-1)
              return dp[i][j];
          
          int count=0;
          
          for(int i1=0;i1<2;i1++){
            int x=i+dx[i1];
            int y=j+dy[i1];
              
          if(x<n && y<m && x>=0 && y>=0){
              count+=find(x,y,n,m);
            }
          }
          
          return dp[i][j]=count;
      }
};