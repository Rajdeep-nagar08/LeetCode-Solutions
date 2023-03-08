class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=piles[0];
      for(int x:piles)
        mx=max(mx,x);
      
      int low=1;
      int high=mx;
      
      while(low<=high){
        int mid=(high-(high-low)/2);
        if(is_valid(mid,piles,h))
          high=mid-1;
        else
          low=mid+1;
      }
      return low;
    }
  
     bool is_valid(int s,vector<int>&piles,int h){
       
       int speed=0;
       
       for(int i=0;i<piles.size();i++)
         speed=speed + ceil(double(piles[i])/double(s));
       
       if(speed > h)
         return false;
       
       return true;
      
     }
};


/*
Binary search the products distributed to every store.
The search range it between left = 1 and right = 10000.
We can also use right = max(A), no big difference.

For a products to distributed,
we needs ceil(A[i] / mid) store,

We sum up the stores we needs and check whether we have that enough stores.
If we have enough stores,
mid is big enough.
then change right = mid-1

If we have no enough stores,
mid is too small,
then change left = mid + 1

Similar question:-

Find the Smallest Divisor Given a Threshold
Koko Eating Bananas


*/


/*

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
      int mx=q[0];
      for(int x:q)
        mx=max(mx,x);
      
      int low=1;
      int high=mx;
      
      while(low<=high){
        int mid=(high-(high-low)/2);
        if(is_valid(mid,q,n))
          high=mid-1;
        else
          low=mid+1;
      }
      return low;
    }
  
     bool is_valid(int p,vector<int>&q,int n){
       
       int store_needed=0;
       
       for(int i=0;i<q.size();i++)
         store_needed=store_needed + ceil(double(q[i])/double(p));
       
       if(store_needed > n)
         return false;
       
       return true;
      
     }
};
*/