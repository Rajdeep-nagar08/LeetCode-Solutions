class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        
        int n=nums.size();
        
        
        vector<int>ans;
        
        deque<pair<int,int>>dq;     
        
        int i=0,j=0;
        
        
        while(i<n){
            
            if(i>=k){
                
                 ans.push_back(dq.front().first);

                
                if((int)dq.size()>0 && dq.front().second==j)
                    dq.pop_front();
                
                j++;
                
            }
            
            
             while((int)dq.size()>0 && dq.back().first<nums[i]){
                    dq.pop_back();
                }
                
                dq.push_back({nums[i],i});
            
            
            
            i++;
        }
        
        
        if(dq.size()>0)
            ans.push_back(dq.front().first);
        
        return ans;
        
    }
};