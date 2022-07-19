/*
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int tar) {
        
     int n=matrix.size();
      int m=matrix[0].size();
    
      pref=vector<vector<int>>(n,vector<int>(m,0));
      
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
           
        
        
    }
};

*/

class Solution {
public:
    int result=0,target;
    unordered_map<int,int> map;
    void get_result(vector<int>& nums)                          //Get number of subarrays that sum to target.
    {
        int sum=0;
        map.clear();
        map[0]++;
        for(int &i:nums)
        {
            sum+=i;
            result+=map[sum-target];       //get number of subarrays who's sum equals target and end at i and add result to global result.
            map[sum]++;                    //Add the occurence of running sum to map.
        }
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        this->target=target;
        vector<int> row(matrix[0].size());
        for(int i=0;i<matrix.size();i++)                    //Convert 2D array to 1D by row.
        {
            fill(row.begin(),row.end(),0);                  //Clear vector to start the row with i as starting row.
            for(int j=i;j<matrix.size();j++)
            {
                for(int x=0;x<matrix[0].size();x++)         //Add next row
                    row[x]+=matrix[j][x];
                get_result(row);
            }
        }
        return result;
    }
};