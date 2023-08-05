
/*
https://leetcode.com/problems/trapping-rain-water/discuss/153992/Java-O(n)-time-and-O(1)-space-(with-explanations).


O(n) time, O(1) space

water stored on top of any building = 

min(maxL,maxR)-height of building


if min(maxL,maxR) < height of building, water stored on top of it=0


[3(maxL),1(l),0,2,4,6,2,0,5(r,maxR)]

maxL > l < r = maxR : water stored on top of 1: (maxL-l) = 2, l++


[3(maxL),1,0(l),2,4,6,2,0,5(r,maxR)]

maxL > l < r = maxR : water stored on top of 0: (maxL-l) = 3, l++


[3(maxL),1,0,2(l),4,6,2,0,5(r,maxR)]

maxL > l < r = maxR : water stored on top of 2: (maxL-l) = 1, l++


[3(maxL),1,0,2,4(l),6,2,0,5(r,maxR)]

Now maxL < l < r = maxR, update maxL, No water stored on top of l or 3, l++

[3,1,0,2,4(maxL),6(l),2,0,5(r,maxR)]

maxL < (l > r = maxR), No water stored on top of 6 and 5 as well

r--, update maxL

[3,1,0,2,4,6(maxL,l),2,0(r),5(maxR)]

maxL = l > r < maxR

water stored on top of r (0) : (maxR-r) = 5, r--


[3,1,0,2,4,6(maxL,l),2(r),0,5(maxR)]

maxL = l > r < maxR

water stored on top of r (2) : (maxR-r) = 3, r--

[3,1,0,2,4,6(maxL,l,r),2,0,5(maxR)]

maxL=l=r<maxR

stop (l==r)


*/

class Solution {
public:
    int trap(vector<int>& height) {
        
      int n=height.size();
      vector<int>pref1(n);
       pref1[0]=height[0];
      
      for(int i=1;i<n;i++)
        pref1[i]=max(pref1[i-1],height[i]);
      
      vector<int>pref2(n);
      pref2[n-1]=height[n-1];
      for(int i=n-2;i>=0;i--)
        pref2[i]=max(pref2[i+1],height[i]);
      
      
      long long int ans=0;
      for(int i=0;i<n;i++){
        if(height[i]==pref1[i] || height[i]==pref2[i])
          continue;
        
        ans=ans + min(pref1[i],pref2[i])-height[i];
      }
        return ans;
    }
};