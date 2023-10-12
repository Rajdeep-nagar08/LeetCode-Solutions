/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*
first find the peak elements index =p
for peak element (mA[p-1]<mA[p]>mA[p+1])
*/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mA) {
        int n=mA.length();
        
        int l=0,h=n-1;
        int p;
        while(l<=h){
            int mid=(l+h)/2;
            
           int prev=mA.get(mid-1);
           int curr=mA.get(mid);
           int next=mA.get(mid+1);
            /*
            if(prev==target)
                return mid-1;
            if(curr==target)
                return mid;
            if(next==target)
                return mid+1;
            */
            if(prev<curr && curr>next){
                p=mid;
                break;
            }
            
            else if(prev<curr && curr<next)
                l=mid+1;
            else if(prev>curr && curr>next)
                h=mid;
        }
        
        //check from 0 to p

         l=0,h=p;
        while(l<=h){
            int mid=(l+h)/2;
            int m=mA.get(mid);
            if(m==target)
                return mid;
            if(m>target)
                h=mid-1;
            else
              l=mid+1;
        }
        
        l=p,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int m=mA.get(mid);
            if(m==target)
                return mid;
            if(m>target)
                l=mid+1;
            else
              h=mid-1;
        }
        
        
        return -1;
        
    }
};

