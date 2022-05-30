class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        
        int i=0,j=0;
        
        // handeling diagonals start from topmost row 
        
        while(j<m){
            int j1=j;
            int i1=0;
            vector<int>v;
            while(i1<n && j1<m){
                v.push_back(mat[i1][j1]);
                i1++,j1++;
            }
            
            sort(v.begin(),v.end());
            
            i1=i,j1=j;
           
            int k=0;
            while(i1<n && j1<m){
                mat[i1][j1]=v[k];
                k++;
                i1++,j1++;
            }
            
            j++;
            
        }
        
        
      
      // handeling diagonals starting from leftmost column and 1st row  
        
        i=1,j=0;
        
        while(i<n){
            int j1=0;
            int i1=i;
            vector<int>v;
            while(i1<n && j1<m){
                v.push_back(mat[i1][j1]);
                i1++,j1++;
            }
            
            sort(v.begin(),v.end());
            
            i1=i,j1=j;
           
            int k=0;
            while(i1<n && j1<m){
                mat[i1][j1]=v[k];
                k++;
                i1++,j1++;
            }
            
            i++;
            
        }
        
        
        return mat;
        
    }  
};