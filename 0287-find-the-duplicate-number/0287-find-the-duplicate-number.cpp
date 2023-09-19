class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();  //[1,n-1]
    
      
      int l=1;
      int r=n-1;
      
      while(l<=r){
        int mid=(l+r)/2;
        
        int count=0;
        for(int x:nums){
          if(x<=mid)
            count++;
        }
          if(count<=mid)
            l=mid+1;
        else
          r=mid-1;
         
      }
        return l;
    }
};