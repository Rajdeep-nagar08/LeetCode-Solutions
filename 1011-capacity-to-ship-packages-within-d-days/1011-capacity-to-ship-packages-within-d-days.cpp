class Solution {
public:
    bool solve (int mid,vector<int>& weights,int days,int n)
    {
        int sum=0;
        int d=1;
        for(int i=0;i<n;i++)
        {
            if(weights[i]>mid)
            {
                return false;
            }
            if(sum+weights[i]<=mid)
            {
                sum+=weights[i];
            }
            
            else
            {
                sum=weights[i];// reset sum 
                d++;
                
                
            }
        }
        
        if(d<=days)
        {
            return true;
        }
        
        
      return false;
        
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n=weights.size();
        int high=0;
        int low=INT_MIN;
          int ans;
        for(int i=0;i<n;i++)
        {
            low=max(low,weights[i]);
            high+=weights[i];
        }
        
        while(low<=high)
        {
            int mid =low+(high-low)/2;
          
         
            if(solve(mid,weights,days,n)==true)
            {
                ans=mid;
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
       
        return ans;
        
        
        
    }
};