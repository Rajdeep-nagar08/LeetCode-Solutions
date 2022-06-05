class Solution {
  int count=0;
public:
    int totalNQueens(int n){
      
      vector<string>board(n,string(n,'.'));
      
      place_queen(0,n,board);
      
      return count;
    }
  
    void place_queen(int row,int n,vector<string>&board ){
      if(row==n){
       // ans.push_back(board);
        count++;
        return;
      }
      
      for(int col=0;col<n;col++){
        if(check(row,col,n,board)==true){
          board[row][col]='Q';
          place_queen(row+1,n,board);
          board[row][col]='.';
        }
      }
    }
  
  
    bool check(int row,int col,int n,vector<string>&board){
      int i,j;
      for(int i=0;i<row;i++){
        for(int j=0;j<n;j++){
          if(board[i][j]=='Q'){
            if((row-col)==(i-j) || (col-row)==(j-i) || (row + col)==(i+j))
              return false;
            else if(j==col)
              return false;
          }
        }
      }
      return true;
    }
};