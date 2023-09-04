
/*
https://leetcode.com/problems/trapping-rain-water/discuss/153992/Java-O(n)-time-and-O(1)-space-(with-explanations).


O(n) time, O(1) space

water stored on top of any building = 

min(maxL,maxR)-height of building


if min(maxL,maxR) < height of building, water stored on top of it=0


[3(maxL),1(l),0,2,4,6,2,0(r),5(maxR)]

maxL < maxR and (maxL>l) : water stored on top of 1: (maxL-l) = 2, l++


[3(maxL),1,0(l),2,4,6,2,0(r),5(maxR)]

maxL< maxR and (maxL>l) : water stored on top of 0: (maxL-l) = 3, l++


[3(maxL),1,0,2(l),4,6,2,0(r),5(maxR)]

maxL < maxR and (maxL > l) : water stored on top of 2: (maxL-l) = 1, l++


[3(maxL),1,0,2,4(l),6,2,0(r),5(maxR)]

Now maxL < maxR but l>maxL, update maxL, No water stored on top of l or 3, l++


[3,1,0,2,4(maxL),6(l),2,0(r),5(maxR)]

maxL < maxR, but l>maxL  No water stored on top of 6 

update maxL

[3,1,0,2,4,6(maxL),2(l),0(r),5(maxR)]

maxL > maxR, and r<maxR,: water stores on top of r =0: (maxR-r) = 5-0=0


[3,1,0,2,4,6(maxL),2(l,r),0,5(maxR)]

maxL > maxR, and r<maxR, water stored on top of r=2: (maxR-r)= 5-2= 3




*/

class Solution {
public:
    int trap(vector<int>& ht) {
        
        
        int n=ht.size();
        
        
        int ans=0;
        
        int mxL=ht[0],i=1;
        
        int mxR=ht[n-1],j=n-2;
        
        while(i<=j){
            
            
            if(mxL<mxR){
                
                if(ht[i]<mxL){
                    ans+=mxL-ht[i];
                }
                else{
                    mxL=ht[i];
                }
                
                i++;
                
            }
            
            else if(mxL>=mxR){
                
                if(ht[j]<mxR){
                    ans+=mxR-ht[j];
                }
                else{
                    mxR=ht[j];
                }
                
                j--;
                
            }
            
        }
        
        return ans;
    }
};