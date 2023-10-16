#define lln long long int
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans(n+1);
      
         ans[0]=ans[n]=1;
      
      for(int r=1;r<=n/2;r++)
        ans[r]=ans[n-r]= (lln)(ans[r-1])*(lln)(n-r+1)/r;
    
  
     return ans;
}

};