class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        
        int n=nums.size();
        
        // x numbers in the array are greater than or eqaul to x, return x
        
        sort(nums.begin(),nums.end());
        
        
        int mx=*max_element(nums.begin(),nums.end());
        
        
        for(int x=0;x<=mx;x++){
            
            int i1=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            
            if(n-i1==x)
                return x;
        }
        
        
        return -1;
        
    }
};