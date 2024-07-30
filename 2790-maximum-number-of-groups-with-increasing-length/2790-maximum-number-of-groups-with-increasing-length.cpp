/*

to maximize the no. of groups, we are keeping one more no. extra in a group than its previous group

let nums= [1,2,3,6]

0 1 time
1 2 times
2 3 times
4 6 times


try to make 6 groups :
 checking from back
 give 4 to all 6 groups
 give 2 to last 5 groups, not possible so return false


try to make 4 groups
   give 4 to all 4 groups
   give 2 to last 3 groups
   give 1 to last 2 groups
   give 0 to last group
[4] [4,2] [4,2,1] [4,2,1,0], ok, but this is wrong approach let take more examples


    
[2,2,2]
   
   make 3 groups
   
   give 2 count of 2 and 1 count of 0 to all 3 groups
   
   now left with [1,2,0]
   
   give 1 to last 2 groups
   
   left with [1,0,0]
   
   can;t give 0 to last group bcs last group already have 1 zero, than there will be duplicate
  
   
   
[2,2,2]
   give 1 from 0 to first group
   now left with [1,2,2]

   give 1 from 1 and 1 from 2 to second group
   
   now left with [1,1,1]
   
   give 1's from 0,1,2 last group
   

clearly we can't calculate valid function using this adhoc based approch



==========================


HERE is the GAP algorithm :

https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/discuss/3807567/O(nlogn)-Binary-search-find-lower-triangular-matrix-easy-to-understand


Let's take a look at a more complex example, usageLimits = [3, 3, 3, 1]

1 2 3
1 2 3
1 2 3 4

We now want to check if 4 is a valid group num. At the first glance, there is no lower triangular matrix of size 4, as the first column only has 3 elements (gap is 4 - 3 = 1). However, we have an extra element (3) in the third column, which can be used to fill the previous gap in the first column. After using that element to fill the gap, we are now able to find a lower triangular matrix of size 4:

[3]           - group 0
 1  2 [ ]     - group 1
 1  2  3      - group 2
 1  2  3  4   - group 3
 
With the idea of filling the previous gap, we can come with an algorithm below:

sort usageLimits from high to low
binary search for the group num groups, in each step
a. initialize gap = 0, h = groups(desired height in the lower triangular matrix)
b. for each column i, update the gap among usageLimits[i], h and previous gap: gap = max(h - usageLimits[i] + gap, 0) and decrease h
c. at the end of the loop, check if gap is 0, if yes, it means we are able to find a lower triangular matrix with size groups.


*/


class Solution {
public:
    int maxIncreasingGroups(vector<int>& limit) {
        
        sort(limit.rbegin(),limit.rend());
        
        int n=limit.size();
    
        /*
        
        trick:
        
           give 1,2,3,4,5,.....n to each consecutive group
        
        
        */
                    

        int l=1,h=n;
        
        int ans;
        
        while(l<=h){
            int mid=(l+(h-l)/2);
            
            if(isValid(mid,limit)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return ans;
        
    }
    
    // is it possible to make mid groups ???
    
    bool isValid(int mid, vector<int>&limit){
        
        
        int gap=0;
        
        for(int i=0;i<limit.size();i++){
            gap=max(mid-limit[i]+gap,0);
            if(mid)
            mid--;
        }
        
         if(gap==0)
             return true;
        
        return false;
    }
};