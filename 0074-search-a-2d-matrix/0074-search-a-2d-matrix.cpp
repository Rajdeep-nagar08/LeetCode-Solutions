class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int k=0;
        for(int i=0;i<matrix.size()-1;i++)
        {
            if(matrix[i][0]==target)
            {
                return true;
            }
           else  if(target>matrix[i][0] && target<matrix[i+1][0])
            {
                k=i;
               break;
               
            }
        }
        
        
        int p=matrix.size()-1;
        
        
        if (target>=matrix[p][0])
        {
            k=p;
        }
        
         for(int j=0;j<matrix[0].size();j++)
        {
            if(target==matrix[k][j])
            return true;
        }
        
      
        return false;
    }
};