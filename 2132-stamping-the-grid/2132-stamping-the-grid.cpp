/*

You can stamp a m * n area if the sum of all elements in that area is zero (no blocked cells). We calculate the prefix sum matrix pref for our grid, and use the range sum 2D approach to find all areas we can stamp.

We will mark right bottom corner of those areas in the stamps grid.

How do we know if a cell [i][j] is covered by some stamp? It is covered if there is a stamp with right bottom corner within [i][j] - [i + h - 1][j + w - 1].

So, we just count stamps within that area. To do it in O(1), we create another prefix sum matrix pref2 from the stamps grid.

*/


class Solution {
public:
    
    bool possibleToStamp(vector<vector<int>>& mat, int H, int W) {
        
     
       int n=mat.size();
      int m=mat[0].size();
        
        auto pref1= formPrefix(mat);
        
        vector<vector<int>>stamp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j+W-1>=m || i+H-1>=n)
                    break;
                if(sumRegion(pref1,i,j,i+H-1,j+W-1)==0){
                    stamp[i+H-1][j+W-1]=1;
                }
            }
        }
        
        auto pref2=formPrefix(stamp);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    if(sumRegion(pref2,i,j,min(i+H-1,n-1),min(j+W-1,m-1))==0)
                        return false;
                }
            }
        }
        return true;
    }
    
    
    vector<vector<int>> formPrefix(vector<vector<int>>&matrix){
       
      int n=matrix.size();
        
      int m=matrix[0].size();
    
      vector<vector<int>>pref(n,vector<int>(m,0));
      
      pref[0][0]=matrix[0][0];
        
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
          
          if(i==0 && j>0)
              pref[i][j]=matrix[i][j]+pref[i][j-1];
            else if(j==0 && i>0)
                pref[i][j]=matrix[i][j]+pref[i-1][j];
              
             else if(i>0 && j>0)  
         pref[i][j]=matrix[i][j]+ pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
            }
          }
      
        
        return pref;
        
        
    }
    
    
    int sumRegion(vector<vector<int>>&pref,int r1, int c1, int r2, int c2) {
        
        if(r1==0 && c1==0)
                return pref[r2][c2];
            else if(r1==0)
                return pref[r2][c2]-pref[r2][c1-1];
            else if(c1==0)
                 return pref[r2][c2]-pref[r1-1][c2];
              else
              
     return pref[r2][c2]-pref[r1-1][c2]-pref[r2][c1-1] + pref[r1-1][c1-1];
              
    }
        
};