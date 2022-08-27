/*
Max sum of matrix <=k

1 2 3   
4 5 6
1 2 4

making prefix sum matrix 
mat[i][j] = mat[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]

1 3  6
5 12 21
6 15 28

28-6-6+1=28-11=17
sum(i1,j1 to i2,j2)= mat[i2][j2]-mat[i1-1][j2]-mat[i2][j1-1]+mat[i1-1][j-1]

To find all rectangular sums => O(n*m * n*m)

So brute Force= O(n*m*n*m)*O(logk)



// OPTIMISED APPROACH: 

*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        
      int ans=INT_MIN;
      int r=mat.size();
      int c=mat[0].size();
  /* as no of rows are larger than no of cols, so keep adding cols instead of adding rows
  */
      
      for(int i=0;i<c;i++){
        vector<int>a(r,0);
        for(int j=i;j<c;j++){
         for(int row=0;row<r;row++){
            a[row]+=mat[row][j];
          }
          
          // now find max cont. sum in this arry <=k , using binary search
          
          int Sum=0,mx=INT_MIN;
          
          set<int>st={0};
          for(int x:a){
            Sum+=x;
            auto it= st.lower_bound(Sum-k);
            if(it!=st.end())
              mx=max(mx,Sum-*it);
            
            st.insert(Sum);
          }
          ans=max(ans,mx);
        }
      }
      return ans;
    }
};