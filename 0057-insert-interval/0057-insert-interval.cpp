/*
First, put all intervals that are to the left of the inserted interval.
Second, merge all intervals that intersect with the inserted interval.
Finally, put all intervals that are to the right of the inserted interval.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInt) {
        
      int n=inter.size();
      
      int i=0;
      vector<vector<int>>ans;
      while(i<n && inter[i][1]< newInt[0]){
        ans.push_back(inter[i]);
        i++;
      }
      
       while(i<n &&  inter[i][0] <= newInt[1]){
          newInt[0]=min(newInt[0],inter[i][0]);
          newInt[1]=max(newInt[1],inter[i][1]);
         i++;
       }
         ans.push_back(newInt);
      
      while(i<n){
         ans.push_back(inter[i]);
        i++;
      }
         return ans;
    }
};