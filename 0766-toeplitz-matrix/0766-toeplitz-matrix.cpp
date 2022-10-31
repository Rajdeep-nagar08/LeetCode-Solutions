class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        int j=0;
        
        while(j<m){
            int j1=j;
            int i1=0;
            
            while(i1<n && j1<m){
                if(mat[0][j]!=mat[i1][j1])
                    return false;
                i1++,j1++;
            }
            j++;
        }
        
        
        int i=0;
        
        while(i<n){
            
            int i1=i;
            
            int j1=0;
            
            while(i1<n && j1<m){
                if(mat[i][0]!=mat[i1][j1])
                    return false;
                i1++,j1++;
            }
            i++;
        }
        
        return true;
    }
};