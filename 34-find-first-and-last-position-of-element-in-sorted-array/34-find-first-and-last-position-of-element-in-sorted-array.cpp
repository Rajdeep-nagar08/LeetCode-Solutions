class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        
        int n=nums.size();
        
        int l=0,h=n-1;
        
        int left=-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            
            else if(nums[mid]>target)
                h=mid-1;
            
            else{
                 
                if(mid==0 || (nums[mid]!=nums[mid-1])){
                    left=mid;
                    break;
                }
                else{
                    h=mid-1;
                }
            }
            
        }
        
        
        l=0,h=n-1;
        
        int right=-1;
        
         while(l<=h){
            int mid=(l+h)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            
            else if(nums[mid]>target)
                h=mid-1;
            
            else{
                 
                if(mid==n-1 || (nums[mid]!=nums[mid+1])){
                    right=mid;
                    break;
                }
                else{
                    l=mid+1;
                }
            }
            
        }
        
        return {left,right};
        
    }
};