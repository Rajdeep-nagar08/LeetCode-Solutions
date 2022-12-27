class Solution {
public:

    bool ans=false;
    int n=9;
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
    
    

    bool solve(vector<vector<char> > &A,int i,int j){
        
                if(i==A.size()){
                    return true;
                }
        
                int ni=0;
                int nj=0;
        
                if(j==A[0].size()-1){
                   nj=0;
                   ni=i+1;
                }else{
                    nj=j+1;
                    ni=i;
                }
        
        if(A[i][j]=='.')
                     {
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(A,i,j,ch-'0')){
                            A[i][j]=ch;
                            if(solve(A,ni,nj))
                                return true;
                            A[i][j]='.';
                        }
                    }
               }
        else
            return solve(A,ni,nj);
        
        return false;
        
        }
 
     
    bool isValid(vector<vector<char>> &board, int i, int j,int val){
        // return false;
        int row=i, col=j;
        j--;
        while(j>=0){
            if(board[i][j]-'0'==val) return false;
            j--;
        }
        j=col+1;
        while(j<n){
            if(board[i][j]-'0'==val) return false;
            j++;
        }
        
        j=col;i=row-1;
         while(i>=0){
            if(board[i][j]-'0'==val) return false;
            i--;
        }
        i=row+1;
        while(i<n){
            if(board[i][j]-'0'==val) return false;
            i++;
        }
        
        int st_x=-1, st_y=-1;
    
        if(row==4||row==1||row==7) st_x=row-1;
        else if(row%3==0) st_x=row;
        else st_x=row-2;
        
        if(col==1||col==4||col==7) st_y=col-1;
        else if(col%3==0) st_y=col;
        else st_y=col-2;
        
         i=st_x, j=st_y;
        
        while(i<=st_x+2){
            j=st_y;
            while(j<=st_y+2){
                if(board[i][j]-'0'==val) return false;
                j++;
            }
            i++;
        }
        return true;
    }
};

