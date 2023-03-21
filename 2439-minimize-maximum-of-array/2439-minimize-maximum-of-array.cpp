class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n=nums.size();
                
        /*
        
        choose any positive no. from array
      
        Binary search
        
        
        
        */
        
        
        int l=0,h=1e9;
        
        int ans;
        
        while(l<=h){
            
            
            int mid=l+(h-l)/2;
            
            if(isValid(mid,nums)){
                ans=mid;
                h=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        
        return ans;
        
    }
    
    
    bool isValid(int mid,vector<int>&v){
        
        int n=v.size();
        
        // vector<int>v1(v);
        
        long long int extra=0;
        
        for(int i=n-1;i>0;i--){
            long long int diff=max(0*1ll,1ll*v[i]+extra-mid);
            extra=diff;
        }
        
        if(v[0]+extra>mid)
            return false;
        
        return true;
        

    }
};