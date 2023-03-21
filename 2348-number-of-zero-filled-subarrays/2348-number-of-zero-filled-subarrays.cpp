
#define lln long long int
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
       lln ans=0;
        
        int n=nums.size();
        
        
        int i=0;
        
        while(i<n){
            
            lln c=0;
            
            if(nums[i]==0){
            while(i<n && (nums[i]==0)){
                i++;
                c++;
              }
            }
            else
                i++;
            
            ans+=1ll*(c*(c+1))/2;
        }
        
        return ans;
    }
};