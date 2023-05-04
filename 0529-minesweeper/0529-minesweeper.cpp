class Solution {
    int dx[8]={1,-1,0,0,1,1,-1,-1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};
public:
    
    int n,m;
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        n=board.size();
        
        m=board[0].size();
        
      
       dfs(click[0],click[1],board);
        
        return board;
        
    }
    
    void dfs(int x,int y, vector<vector<char>>&board){
        
        if(board[x][y]=='M'){
            board[x][y]='X';
            return;
        }
        
        
        if(board[x][y]=='E'){
            
            int c=0;  // adjacent mines
            
            for(int i=0;i<8;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<n && y1<m && x1>=0 && y1>=0){
                if(board[x1][y1]=='M'){
                    c++;
                }
            }
        }
            
            if(c==0){
                
                board[x][y]='B';
                
            for(int i=0;i<8;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<n && y1<m && x1>=0 && y1>=0 && (board[x1][y1]=='M' || board[x1][y1]=='E')){
                dfs(x1,y1,board);
            }
        }
                
    }
            
            else{
                board[x][y]=c+'0';
                return;
            }
            
        }
    }
};