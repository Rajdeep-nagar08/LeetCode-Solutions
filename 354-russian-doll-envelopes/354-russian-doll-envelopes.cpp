/*
sort the array according to increasing order of height, if heights are same then decreasing order of width

now find longest icreasing subsequence based on weidth ( as height are already sorted, and all envelops of same height will never be in our answer as we sort their weidth in decreasing order(so these will never be a part if LIS)
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        
      int n=(int)nums.size();
        
    sort(nums.begin(),nums.end(),[](const vector<int>&v1,const vector<int>&v2){
        if(v1[0]<v2[0])
            return true;
        else if(v1[0]==v2[0])
          return v1[1]>v2[1];
        else
          return false;
    });
        
//LIS
        
        vector<int>v;
        
        for(int i=0;i<n;i++){
            int idx=lower_bound(v.begin(),v.end(),nums[i][1])-v.begin();
            if(idx==(int)v.size())
                v.push_back(nums[i][1]);
            else
            v[idx]=nums[i][1];
        }
        return (int)v.size();
        
    }
};