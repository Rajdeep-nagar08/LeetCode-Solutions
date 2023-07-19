//GREEDY
/* 
if next interval intersact with previopus interval then remove that interval out of both whose right limit is smaller so that it will intersect with less no. of intervals in future and update previous intetrval right limit accourdingly to check intersactuion with incoming intervals
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
      
      int count=0;

      int r=inter[0][1];
  
        for(int i=1;i<inter.size();i++){
          
          int l1=inter[i][0];
          if(l1<r){
            count++;
            if(r>inter[i][1])
              r=inter[i][1];
          }
           else
             r=inter[i][1];
        }
      return count;
    }
};