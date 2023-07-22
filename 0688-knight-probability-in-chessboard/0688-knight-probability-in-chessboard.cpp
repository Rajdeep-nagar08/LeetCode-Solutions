int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
double dp[26][26][101];
class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        memset(dp,-1,sizeof(dp));
        
       return getProb(n,k,r,c);
    }
    
    double getProb(int n,int k,int x,int y){
  if(x<0 || y<0 || x>=n || y>=n)
            return 0.0;
        if(k==0)
         return 1.0;
        
  if(dp[x][y][k]!=-1 && dp[x][y][k]*0.0==0)
      return dp[x][y][k];
    
        double ans=0.0;
        for(int i=0;i<8;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
        ans=ans+getProb(n,k-1,x1,y1);
        }
        return dp[x][y][k]=ans/8.0;
    }
    
    /*
    
    dp[i][j][k]= probability that knight remains on chess board after k moves from (i,j)
    
    */
    
};