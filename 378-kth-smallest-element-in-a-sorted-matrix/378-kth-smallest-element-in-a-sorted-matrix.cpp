class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int ans=0;
      int n=mat.size();
      int low=mat[0][0];
      int high=mat[n-1][n-1];
      while(low<=high){
        int mid=(high-(high-low)/2);
        if(smallerThenMid(mat,mid)>=k){
          ans=mid;
          high=mid-1;
        }
        else
          low=mid+1;
      }
      return ans;
    }
  
     int smallerThenMid(vector<vector<int>>&mat,int x){
       int j=mat[0].size()-1;
       int count=0;
       for(int i=0;i<mat.size();i++){
         int idx=upper_bound(mat[i].begin(),mat[i].end(),x)-mat[i].begin();
         count+=idx;
       }
       return count;
     }
};