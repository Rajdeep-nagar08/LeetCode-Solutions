/*
https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633401/Kadane-Algorithm-Trick-beats-100-Java-Explained
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
      
    // finding min subarray
      int mn=INT_MAX;    
      int temp1=0;
      for(int i=0;i<n;i++){
       temp1=min(nums[i],temp1+nums[i]);
        mn=min(mn,temp1);
        
      }
      
    // finding max_subarray  
       int mx=INT_MIN;
      int temp2=0;
      for(int i=0;i<n;i++){
        temp2=max(nums[i],temp2+nums[i]);
        mx=max(mx,temp2);
        
      }
      
     int sum=0;
      for(int x:nums)
        sum=sum+x;
      
      int circular_max=sum-mn;
      int non_circular_max=mx;
      
        
       // cout<<circular_max<<" "<<non_circular_max<<endl;
        
     // corner case
      if(circular_max==0){      // return max non_circular subarray in this case
       return non_circular_max;
      }
      
      
      return max(circular_max,non_circular_max); 
      
    }
};




/*
kadans(to find maximum sum contigous subarray)
for(int i=0;i<n;i++){
tem=max(arr[i],temp+arr[i]);
mx=max(mx,temp);
}
*/

/*  https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/633401/Kadane-Algorithm-Trick-beats-100-Java-Explained

*/

/*
The maximum subarray sum in circular array is maximum of following

Maximum subarray sum in non circular array
Maximum subarray sum in circular array.
Example - [1,2,5,-2,-3,5]
Steps -

Find the maximum subarray sum using Kadane Algorithm. This is maximum sum for non circular array.
image
1+2+5 = 8
For non circular sum,
Step 1) find the minimum subarray sum of array.
image
-2-3 =-5
Step 2) Now find the total sum of array = 1 + 2 + 5 -2 - 3 + 5 = 8
Step 3) The max subarray sum for circular array = Total Sum - Minimum subarray Sum
= 8 - (-5) = 8 + 5 =13
image
As illustrated above, substracting minimum subarray sum from total sum gives maximum circular subarray sum.
Answer = Max ( Non circular max sum + circular max sum )= max(8,13) = 13


*/