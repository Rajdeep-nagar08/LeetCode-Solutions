class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        vector<int>ans;
        
        while(top<=bottom && left<=right)
        {
            
        
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
            
        if(top>bottom)
            break;
            
            for(int i=top;i<=bottom;i++)
            {

 ans.push_back(matrix[i][right]);
            
            }
            right--;
            
            if(right<left)
                break;
            
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            if(bottom<top)
                break;
            
        
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
             left++;
            
            if(left>right)
                break;
            
              
        }
        return ans;
    
    }
};