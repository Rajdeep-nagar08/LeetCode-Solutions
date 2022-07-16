int mod=1e9+7;


int dp[51][51][51];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

class Solution {
public:
    int findPaths(int n, int m, int maxMove, int sr, int sc) {
        
        /*
        
        atmost 'maxMove'
        
        No of paths to move the ball out of the grid = ?
        
        
        
        dp[i][j][move]= no of paths to maove the ball out of the grid if ball is currently at [i,j] , in total 'move' moves
        
        Ans= dp[sr][sc]
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        return find(sr,sc,maxMove,n,m)%mod;
        
        
    }
    
    int find(int i,int j,int move,int n,int m){
        if((i>=n || j>=m || i<0 || j<0) && (move>=0))
            return 1;
      
        if(move==0)
            return 0;
        
        if(dp[i][j][move]!=-1)
            return dp[i][j][move];
        
        int c=0;
        
        for(int x=0;x<4;x++){
            int x1=i+dx[x];
            int y1=j+dy[x];
           c=(c%mod+find(x1,y1,move-1,n,m)%mod)%mod;
        }
            
        return dp[i][j][move]=c%mod;
    }
    
    
};