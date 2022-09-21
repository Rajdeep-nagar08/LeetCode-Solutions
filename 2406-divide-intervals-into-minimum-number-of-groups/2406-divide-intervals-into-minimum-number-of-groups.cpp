class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
		// Sort intervals based on the start
        sort(intervals.begin(), intervals.end());
        
		// Heap stores the ending interval of each group
        priority_queue<int,vector<int>,greater<int>> heap;
        
        int ans = 1;
		heap.push(intervals[0][1]);

        for(int i=1; i<intervals.size(); i++){
			// If the current interval merges with the min group, then it should be added in new group 
			// No need to check with other group intervals, because it merges with all other groups as we're maintaing min heap
            if(intervals[i][0] <= heap.top()){
                heap.push(intervals[i][1]);
            }
			// Curr interval not merging with min group, then update the group interval
            else{
                heap.pop();
                heap.push(intervals[i][1]);
            }
        }
        
        return heap.size();
    }
};