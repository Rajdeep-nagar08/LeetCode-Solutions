class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         map<int,int>mp;
        for(int x:nums)
            mp[x]++;
        nums.clear();
        for(auto x:mp)
        nums.push_back(x.first);
                
        return nums.size();
    }
    
};
