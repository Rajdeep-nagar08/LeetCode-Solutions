class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int sum=0;
        
        int prevsum=0;
        for(int x:nums){
            sum=(sum+x)%k;
            if(mp[sum]>0)
                return true;
            
            mp[prevsum]++;
            
            prevsum=sum;
            
        }
        
        return false;
    }
};