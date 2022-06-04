class Solution {
public:
    vector<vector<string>>ans;
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n);
        
        string str="";
        
        for(int i=0;i<n;i++)
            str+=".";
        
        for(int i=0;i<n;i++)
            board[i]=str;
        
        find(0,n,board);
        
        return ans;
    }
    
      void find(int r,int n,vector<string>board){
          
          if(r==n){
              ans.push_back(board);
              return ;
          }
          
          for(int c=0;c<n;c++){
              if(isValid(r,c,board,n)){
                  board[r][c]='Q';
                  
                  find(r+1,n,board);
                    //  return true;
                  
                  board[r][c]='.';

              }
             // return false;
          }
         // return false;
      }
    
  
    bool isValid(int r,int c,vector<string>&board,int n){
        for(int i=0;i<r;i++){
          for(int j=0;j<n;j++){
              if(board[i][j]=='Q'){
            if(i==r || j==c || (i-j)==(r-c) || (j-i)==(c-r)  || (i+j)==(r+c))
                      return false;
              }
          }
        }
        return true;
    }
   
};