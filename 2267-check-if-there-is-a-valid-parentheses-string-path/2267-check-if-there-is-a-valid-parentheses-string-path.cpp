/*

Using Backtracking 

 
         when reached at [n-1,m-1] check the string using stack whether it is balanced         or not
         
         Finally return "Yes" if stack size ==0
         
         otherwise return back and try another pass
         
Give TLEEEEEEEEEE


from [i,j] we have two choices to move => right or down

if [0,0] to [i,j] is balanced than ([i+1,j] or [i,j+1]) to [n-1,m-1] should be balanced

if [0,0] to [i,j] is not balanced than [0,0] to [n-1,m-1] should be balanced

dp[i][j][open]= is path from ([i+1,j] or [i,j+1]) to [n-1,m-1] balanced or not, open = no. of extra open brackets  

from [0,0] to [i,j] is balanced or not

(note if there no. of openening bracks <0 then not proceed as string cannot be balnced in future )

*/

int dp[101][101][501];

class Solution {
public:
    
    int n,m;
    
    int dx[2]={1,0};
    
    int dy[2]={0,1};
    
    bool hasValidPath(vector<vector<char>>& grid) {
    
         n=grid.size();
        
         m=grid[0].size();
        
        if(grid[0][0]==')')
            return false;
        
        memset(dp,-1,sizeof(dp));
    
        
        if(find(0,0,1,grid))
            return true;
        
        return false;
        
    }
    
      int find(int i,int j,int open,vector<vector<char>>&grid){
         
          if(i==n-1 && j==m-1){
                          
              if(open==0)
                  return 1;
              
              return 0;
        
              
          }
         
          
          if(dp[i][j][open]!=-1)
              return dp[i][j][open];
         
          
          int ans=0;
          
          int open1=open;
          
          for(int i1=0;i1<2;i1++){
              
              int x1=i+dx[i1];
              
              int y1=j+dy[i1];
             
              if(x1>=n || y1>=m || x1<0 || y1<0)
                   continue;
                 
                 if(grid[x1][y1]==')')
                 {
                     if(open-1>=0)
                         ans=ans|find(x1,y1,open-1,grid);
                 }
              
              else{
                  
                  
                ans=ans|find(x1,y1,open+1,grid);

                  
              }
              
        }
              
          
          return dp[i][j][open1]=ans;
         
      }
    
   
};
