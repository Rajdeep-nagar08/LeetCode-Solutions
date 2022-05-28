class Solution {
public:
    int search(vector<int>& nums, int tar) {
        
        int n=nums.size();
        
        int l=0,h=n-1;
        
        if(nums[0]==tar)
            return 0;
        if(nums[n-1]==tar)
            return n-1;
        
        int mid;

        while(l<=h){
            mid=(l+h)/2;
        //    cout<<mid<<endl;
            if(nums[mid]==tar)
                return mid;
            
            if(nums[0]<=nums[mid]){
            // [0,mid] is sorted
               if(tar<=nums[mid] && tar>=nums[0]){
                 //target in [0,mid]
                   if(tar==nums[0])
                       return 0;
                   if(tar==nums[mid])
                     return mid;
                   if(tar<nums[mid])
                       h=mid-1;
                   else
                       l=mid+1;
               }
              else{
                 // target in [mid+1,.....]
                 l=mid+1;   
                }
              }
            
            else{
                
        //[mid,n-1] is sorted
         if(tar>=nums[mid] && tar<=nums[n-1]){
             //target in [mid,n-1]
             if(tar==nums[n-1])
                 return n-1;
             if(tar==nums[mid])
                 return mid;
             if(tar>nums[mid])
                 l=mid+1;
             else
                 h=mid-1;
             }
         else{
           // target in [.....,mid-1]
             h=mid-1;
             
         }
       }
    }
            
      return -1;
    }
};