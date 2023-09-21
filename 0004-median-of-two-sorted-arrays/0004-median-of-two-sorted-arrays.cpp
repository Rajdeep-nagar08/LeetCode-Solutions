class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n1=nums1.size();
        
      int n2=nums2.size();
        
      double ans;
   
      if(n1>n2)
        return findMedianSortedArrays(nums2,nums1);
        
      int l=0;
        
      int h=n1;
        
      double cut1,cut2,l1,l2,r1,r2;
        
      while(l<=h){
          
        cut1=(h-(h-l)/2);
          
        cut2=((n1+n2+1)/2)-cut1;
          
        l1=cut1==0?INT_MIN:nums1[cut1-1];
          
        l2=cut2==0?INT_MIN:nums2[cut2-1];
          
        r1=cut1==n1?INT_MAX:nums1[cut1];
          
        r2=cut2==n2?INT_MAX:nums2[cut2];
        
        if(l1>r2)
          h=cut1-1;
        else if(l2>r1)
          l=cut1+1;
        else
           break;
          
      }
        
        
    ans=(n1+n2)%2==0?(double)(max(l1,l2)+min(r1,r2))/2:max(l1,l2);

      return ans;
    }
};