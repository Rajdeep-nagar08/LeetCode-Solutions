class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        
        
        
        // pt[i] = no of days needs to plant ith seed, from next day plant will start growing
        
        // gt[i] = time taken by ith seed to grow (after planting) , next day plant will bloom
        
        // so total time taken by ith seed to grow = pt[i]+gt[i] and it will bloom on pt[i]+gt[i]+1 day
        
        // plant trees in any order, earliest time for all plants to bloom
        
       int n = pt.size();
        vector<pair<int, int>> plant(n);        
        
        for(int i=0; i<n; i++) {
			// store growTime[i] & plantTime[i] in pair
            plant[i] = {gt[i], pt[i]};
        }
        
		// sort the vector in non-increasing order 
		// to get grow time of plants in descending order
        sort(plant.rbegin(), plant.rend());
        
        int day = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
			// update value of day when planting
            day += plant[i].second;
			// update ans with max of current day + grow time
            ans = max(ans, day+plant[i].first);
        }
        
        return ans;
       
        
    }
};