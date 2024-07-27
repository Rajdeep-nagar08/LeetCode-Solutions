/*

similar :
https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/


Difference Array Algorithm
===========================

For a given integer array A of length n, its Difference Array D with length 1 + n is defined such that D[i]=A[i]−A[i−1] for 1≤ i< n, with D[0]=A[0] and D[n]=A[n−1].

For example, if the given array is A = [3, 5, 1, 2], its Difference Array is [3, 2, -4, 1, -2].

Difference arrays are useful when we want to efficiently perform range updates (increasing or decreasing elements in a subarray by a constant value) on an array.

For example, if we want to increase A[1 : 2] by 1, the new array A becomes [3, 6, 2, 2], and the resulting Difference Array is [3, 3, -4, 0, -2].

We can observe that when we increase a value x over a subarray [l : r], the effect on the Difference Array D is as follows: D[l] is incremented by x, and D[r + 1] is decremented by x.


suppose :

nums=[9,3,5,7,11] => [9,3,5,7,11,0]=>  DA1=[9,-6,2,2,4,-11]

target=[9,3,5,7,11] => [9,3,5,7,11,0] DA2=[9,-6,2,2,4,-11]


let increment nums[1..3] by 3

nums=[9,6,8,10,11,0] DA1=[9,-3,2,2,1,-11] 

clearly DA1[1] incremented by 3 and DA1[4] decremented by 4   
(no. of increment == no of decrement)


in this condition if someone told me to make nums==target by incrementing any subarray

DA1=[9,-3,2,2,1,-11] DA2=[9,-6,2,2,4,-11]

no. of opertions = count of no. of increment or no of decrement

9-9=0
-3-(-6) = 3 incremenet of 3
2-2=0
2-3=0
1-4= -3 decrement of 3
-11-(-11) = 0

ans= 3


*/


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n=target.size();
        
        target.push_back(0);
        
        vector<int>initial(n+1,0);
        
        int ans=0;
        
        for(int i=0;i<=n;i++){
            int d1=initial[i];
            int d2=target[i];
            if(i>0){
                d1-=initial[i-1];
                d2-=target[i-1];
            }
            
            if(d1>d2)
                ans+=d1-d2;
        }
        
        return ans;
        
    }
};