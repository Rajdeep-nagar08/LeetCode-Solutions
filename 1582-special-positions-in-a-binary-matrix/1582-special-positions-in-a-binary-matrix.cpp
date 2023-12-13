class Solution {
public:
    bool rowcheck(int row , int column , int m , int n , vector<vector<int>>& mat){
        for(int i=0 ; i<n ; i++){
            if(i!=column && mat[row][i] == 1){
                return false;
            }
        }
        return true;
    }
    bool columncheck(int row , int column , int m , int n , vector<vector<int>>& mat){
        for(int j=0 ; j<m ; j++){
            if(j!=row && mat[j][column] == 1){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        int ans = 0 ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] == 1){
                    if(rowcheck(i,j,m,n,mat) && columncheck(i,j,m,n,mat)) ans++;
                }
            }
        }
        return ans;
    }
};