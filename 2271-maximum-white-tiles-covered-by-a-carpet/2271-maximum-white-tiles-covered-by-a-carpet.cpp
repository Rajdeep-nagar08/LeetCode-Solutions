/*

fro,m each starting point , find the point upto which carpet can be placed using binary search

*/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& til, int len) {
        
       sort(til.begin(),til.end());
        
        int n=til.size();
        
         vector<vector<int>>v(n,vector<int>(3));
        
        int d=0;
        
        for(int i=0;i<n;i++){
            int s=til[i][0];
            int e=til[i][1];
            
            v[i]={s,e,d};
            
            if(i<=n-2)
                d+=til[i+1][0]-til[i][1]-1;

        }
   
         int count=0;
        
          for(int i=0;i<n;i++){
              
              int c1=v[i][0];
              
              int need=c1+len-1;
              
              vector<int>v1={need,INT_MAX,INT_MAX};

              
              int idx=upper_bound(v.begin()+i,v.end(),v1)-v.begin();
              
              idx--;
                             
              if(need>v[idx][1])
                  count=max(count,(v[idx][1]-v[i][0]+1)-(v[idx][2]-v[i][2]));
              else
                  count=max(count,(need-v[i][0]+1)-(v[idx][2]-v[i][2]));
              
          }
        
        return count;
        
      }
};