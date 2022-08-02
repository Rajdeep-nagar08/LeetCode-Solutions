class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        
        int n=matrix.size();
        
        
        int high=matrix[n-1][n-1];
        
        int low=matrix[0][0];
        
        while(low<=high)
        {
        
        int mid=(high+low)/2;
        
        int count =0;
        
        for(int i=0;i<n;i++)
        {

count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)- matrix[i].begin();
            
            
        }
            
            if(count<k)
            {
                low=mid+1;
            }
            
            else
            {
                high=mid-1;
            }
        
            
        }
        
        return low;
    }
};