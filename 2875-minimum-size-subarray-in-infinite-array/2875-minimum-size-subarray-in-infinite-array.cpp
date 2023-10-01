#define lln long long int

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        
        int n=nums.size();
        
        
        vector<int>v(nums);
        
        lln sum=0;
        
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
            sum+=nums[i];
        }
        
        int x=smallest(nums,target);
        
        lln tar = target% sum;
        
        int ans= (target/sum)*n;
        
        if(tar==0)
            return ans;
        
        int mn1=INT_MAX;
        
        int mn2=INT_MAX;
        
        lln s1=0;
        
        for(int i=0;i<n;i++){
            s1+=nums[i];
            if(s1==tar){
                mn1=i+1;
                break;
            }
        }
        
        
        lln s2=0;
        
        for(int i=n-1;i>=0;i--){
            s2+=nums[i];
            if(s2==tar){
                mn2=n-i;
                break;
            }
        }
        
        int mn3= smallest(v, tar);
                
                      
        if(mn1==INT_MAX and mn2==INT_MAX and mn3==INT_MAX and x==INT_MAX)
            return -1;
        
          return min(x,ans+min({mn1, mn2, mn3}));

        
        
    }
    
    
    int smallest(vector<int> & arr, int k ){
 
    // Use map here to store the prefixSum ending
    // at ith index.
    unordered_map<long long, int> unmap;
    int n = arr.size();
 
    // Store the current Prefix sum till ith index;
    long long currPrefixSum = 0;
 
    // Store the minimum size subarray whose sum is K
    long long result = INT_MAX;
 
    for(int i = 0; i < n; i++){
        currPrefixSum += arr[i];
 
        // Check if the current prefix sum is equals to K
        if(currPrefixSum == k){
            long long currLen = i + 1;
            result = min(result, currLen);
        }
 
        // Required PrefixSum
        long long requirePrefixSum
            = currPrefixSum - k;
 
        // Check if there exist any required
        // Prefix Sum or not
        if(unmap.count(requirePrefixSum)){
            long long foundIdx =
                unmap[requirePrefixSum];
            long long currIdx = i;
 
            result = min(result,
                           currIdx - foundIdx);
        }
 
        // Store the current prefix sum ending
        // at i
        unmap[currPrefixSum] = i;
    }
 
    if(result >= INT_MAX) 
        
        return INT_MAX;
    // return the result
        
        
    return result;
}
    
    
};