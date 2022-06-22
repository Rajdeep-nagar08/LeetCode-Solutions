class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i=0;
        
        int n=nums.size();
        
        while(i<n && pq.size()<k){
            pq.push(nums[i]);
            i++;
        }
        
        while(i<n){
            pq.push(nums[i]);
            pq.pop();
            i++;
        }
        
        return pq.top();
        
    }
};