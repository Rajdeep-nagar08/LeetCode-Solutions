class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        
        int n=nums.size();
        
        deque<pair<int,int>>dq;
        
        int ans=nums[0];
        
        dq.push_back({0,nums[0]});
        
        
        for(int i=1;i<n;i++){
                        
            while(dq.size()>0 && i-dq.front().first>k)
                dq.pop_front();
            
            int MaxSumTillNow=dq.front().second;

            int MaxSumCurrently=nums[i]+max(0,MaxSumTillNow);
            
            ans=max(ans,MaxSumCurrently);
            
            while(dq.size()>0 && (dq.back().second<MaxSumCurrently))
                dq.pop_back();
            
            dq.push_back({i,MaxSumCurrently});
            
        }
        
        
        return ans;
        
    }
};