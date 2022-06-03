class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        
      int n=matrix.size();
      int m=matrix[0].size();
    
      mat=vector<vector<int>>(n,vector<int>(m,0));
      
      mat[0][0]=matrix[0][0];
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
          
          if(i==0 && j>0)
              mat[i][j]=matrix[i][j]+mat[i][j-1];
            else if(j==0 && i>0)
                mat[i][j]=matrix[i][j]+mat[i-1][j];
              
             else if(i>0 && j>0)  
                mat[i][j]=matrix[i][j]+ mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
            }
          }
      
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(r1==0 && c1==0)
                return mat[r2][c2];
            else if(r1==0)
                return mat[r2][c2]-mat[r2][c1-1];
            else if(c1==0)
                 return mat[r2][c2]-mat[r1-1][c2];
              else
              
               return mat[r2][c2]-mat[r1-1][c2]-mat[r2][c1-1] + mat[r1-1][c1-1];
              
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

