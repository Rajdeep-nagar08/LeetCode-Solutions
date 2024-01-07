class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int>ans;
        
        deque<int>dq;  // index
        
        // size of sliding window = k
        
        // if current index = i, then i-dq.front()+1<=k
        
        int i=0;
        
        while(i<n){
            
            while(dq.size()>0 and nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            while(dq.size()>0 and i-dq.front()+1>k){
                dq.pop_front();
            }
            
            if(i+1>=k)
            ans.push_back(nums[dq.front()]);
            
            i++;
            
        }
        
        return ans;
        
    }
};