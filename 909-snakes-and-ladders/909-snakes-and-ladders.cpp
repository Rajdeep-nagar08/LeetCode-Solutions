
/*
        
        from each cell we have 6 choices to move ,
        
        so we can think about dp
        
        dp[i] = min steps needed to move from i to n^2 if we take any step in a range min(i+6,n^2)
        
        but what about the cyclic loops ?
        
        e.g
        
        17=>13=>17=>13
        
        such cyclic loops never ends during recursion so it causes TLE if we move with recursive solution
        
        Than another method to find the shortest path is BFS
        
        Applying BFS
        
        During BFS , if shortest path > n*n
        
        return -1 (no path possible)
        
        
        Index of no x ? 
        
        Note if size of square = n
        
        int r= n-(x/n)-(x%n==0?-1:0)
        
        int c;
        if((n-r+1)%2==1)  // left to right{
        int start=n*(n-r)+1;
        c=x-start+1;
        }
        else{    // right to left
          int start=n*(n-r)+1;
          c=n-(x-start);
        }
        
        
        
        than index(1 based) of no x = [r][c]
        
        index(0 based) of no x  = [r-1][c-1]

*/
        
        
class Solution {
public:
    int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        
        n=board.size();
        
        int step=0;
        
        int ans=bfs(board,step);
        
        return ans;
            
       }
    
    int bfs(vector<vector<int>>&board,int &step){
       
       queue<int>q;
        
        q.push(1);
        
        vector<bool>vis(n*n+1,false);
        
        vis[1]=true;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                int curr=q.front();
                q.pop();
                
                if(curr==n*n)
                    return step;
                
            for(int k=1;k<=6;k++){
                
             int x=curr+k;
             
             if(x>n*n)
                 break;
             
             int r=n-(x/n)+(x%n==0?1:0);
             int c;
             if((n-r+1)%2==1){
                 int start=n*(n-r)+1;
                 c=x-start+1;
             }
             else{
                 int start=n*(n-r)+1;
                 c=n-(x-start);
             }
              
            if(board[r-1][c-1]==-1){
                if(vis[x]==false){
                    vis[x]=true;
                q.push(x);
                }
            }
            else
            {
                int y=board[r-1][c-1];
                if(vis[y]==false){
                    vis[y]=true;
                q.push(y);

                }
              }
                
            }      
         }
        
            step++;
            
        }
        
        return -1;
        
    }
    
    
};