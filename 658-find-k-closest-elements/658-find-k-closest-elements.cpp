class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     
     int n=arr.size();
        
    priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            
            pq.push({abs(arr[i]-x),i});
            
            if(pq.size()>k)
                pq.pop();
            
        }
        
        vector<int>ans;
        
        while(pq.size()>0){
            int idx=pq.top().second;
            
            ans.push_back(arr[idx]);
            
            pq.pop();
            
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};