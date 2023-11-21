int mod=1e9+7;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        
        int n=nums.size();
        
        /*
        
        
        nums[i]-rev(nums[i]) == nums[j]-rev(nums[j])
        
        
        
        */
        
        unordered_map<int,int>mp;
        
        int ans=0;
        
        for(int i=n-1;i>=0;i--){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            int x=stoi(s);
            int sum=nums[i]-x;
            ans=ans+mp[sum];
            ans%=mod;
            mp[sum]++;
            
        }
        
        return ans%mod;
        
    }
};