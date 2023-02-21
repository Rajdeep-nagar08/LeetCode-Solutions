class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int l=0, h=n-1;
        
        while(l<=h){
            
            int mid=(h+l)/2;
            
            
            if(mid!=0 && mid!=n-1){
                
                if(nums[mid+1]!=nums[mid] && (nums[mid-1]!=nums[mid]))
                    return nums[mid];
                
                if(nums[mid]==nums[mid+1]){
                    
                    if(mid%2){
                       
                        h=mid-1;
                        
                    }
                    else{
                        
                        l=mid+1;
                        
                    }
                    
                }
                else{
                    
                    if(mid%2){
                        
                        l=mid+1;
                        
                    }
                    
                    else{
                        
                        h=mid-1;
                        
                    }
                    
                }
                
            }
            
            else{
                
                
                return nums[mid];
                
            }
            
        }
        
        return -1;
        
    }
};