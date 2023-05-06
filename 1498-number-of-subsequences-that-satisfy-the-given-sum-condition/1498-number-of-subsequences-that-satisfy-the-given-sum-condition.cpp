/*

Use 2 pointers approach let say i and j.
i=0 and j=n-1;

now if(nums[i]+nums[j]<=target) then we can make substrings out of that
next thing from this how many substrings we can make we need to maintain nums[i[ as minimum we need to take it and the maximum element can be any from i+1 to j
So, for every element we have two choices whether to take or not so, we have 2^(j-i) substrings out of that. and i++;
else j--
*/

#define lln long long int
int mod=1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n= nums.size();
        
        sort(nums.begin(),nums.end());
        
       // precomputing pow(2,i)
        
        vector<lln>pow(n+1);
        pow[0]=1;
        for(int i=1;i<=n;i++){
            pow[i]=2*pow[i-1]%mod;
        }
        
        int l=0,r=n-1;
        lln ans=0;
        
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans=(ans%mod + pow[r-l]%mod)%mod;
                l++;
            }
            
            else 
                r--;
                
        }
        
        return ans%mod;
    }
   
};