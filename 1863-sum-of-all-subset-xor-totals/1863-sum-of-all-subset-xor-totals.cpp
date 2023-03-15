class Solution {
public:
    
    int ans=0;
    
    int subsetXORSum(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=1;i<=((1<<n)-1);i++){
            
            int mask=i;
            
            int xr=0;
            
            for(int j=0;j<32;j++){
                
                if(mask & (1<<j)){
                    xr=xr^nums[j];
                }
            }
            
            ans+=xr;
        }
        
        return ans;
    }
    
    
};