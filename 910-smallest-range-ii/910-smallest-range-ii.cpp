/*

After sorting the array

for any index i -:

(A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K)

mx=max(A[i]+k,A[n]-k)
mn=min(A[0]+k,A[i+1]-k)

ans=min(ans,mx-mn)

*/
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
      
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int ans=nums[n-1]-nums[0];
        
        for(int i=0;i<n-1;i++){
            int mx=max(nums[i]+k,nums[n-1]-k);
            int mn=min(nums[0]+k,nums[i+1]-k);
            
            ans=min(ans,mx-mn);
        }
        
        return ans;
    }
};