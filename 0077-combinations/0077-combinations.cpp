/*
dea is using backtracking ,every time I push a number into vector,then I push a bigger one into it;
then i pop the latest one,and push a another bigger one...
and if I has push k number into vector,I push this into result;
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      
     vector<vector<int>>ans;
      if(n<k)
        return ans;
      vector<int>temp;
      find(1,n,k,ans,temp);
      
      return ans;
    }
     
    void find(int i,int j,int k, vector<vector<int>>&ans,vector<int>&temp){
      
      if(k==0){
        ans.push_back(temp);
        return;
      }
      
        for(int s=i;s<=j;s++){
          
          temp.push_back(s);
          k--;
          find(s+1,j,k,ans,temp);
          temp.pop_back();
          k++;
        }
    }
};
  
   