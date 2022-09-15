class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return atmost(nums,k)-atmost(nums,k-1);
    }
    
    int atmost(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int i=0,j=0,total=0,ans=0;
        while(j<nums.size()){
            if(mp[nums[j]]==0)
                total++;
            mp[nums[j]]++;
            if(total>k){
                while(total>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        total--;
                    i++;
                }
            }
            
            ans=ans+(j-i+1);
            j++;
            
        }
        return ans;
    }
};