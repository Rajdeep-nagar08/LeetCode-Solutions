
/*

observation:

if [.....(min......max).....]

is some no. are duplicates inside this range then some no's are also missing from this range so we can easily convert those duplicate no's to the missing no's also we can convert the no's outside the range to missing no's inside the range so our smallest and the greatest no will remain unchanged

as max-min==n-1


*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        
        int n=nums.size();
        
        unordered_map<int,int>mp;
        
        for(int x:nums){
            mp[x]++;
        }
        
        nums.clear();
        
        for(auto it:mp){
            nums.push_back(it.first);
        }
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        
        int j=0;
        
        int ans=n;
        
        while(i<nums.size()){
                       
            
            while(j<nums.size() && (nums[j]-nums[i]<=n-1))
                j++;
            
            
            ans=min(ans,n-(j-i));
            
            i++;
                   
        }
        
        return ans;

    }
};