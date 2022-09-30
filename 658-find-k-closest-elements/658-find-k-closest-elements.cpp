class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     // TC= O(nlogn) , SP= O(n)
      /*
      vector<pair<int,int>>v;
      for(int y:arr)
        v.push_back({abs(x-y),y});
      
      sort(v.begin(),v.end());

        vector<int>ans(k);
      for(int i=0;i<k;i++)
        ans[i]=v[i].second;
      
      sort(ans.begin(),ans.end());
      
      return ans;
      */
      
      // TC= O(nlogk) , SC=O(k)
      
      priority_queue<pair<int,int>>pq;
      
      for(int i=0;i<k;i++)
        pq.push({abs(x-arr[i]),arr[i]});
      
      for(int i=k;i<arr.size();i++){
        pq.push({abs(x-arr[i]),arr[i]});
        pq.pop();
      }
      
      vector<int>ans;
      
      while(pq.size()>0){
      ans.push_back(pq.top().second);
        pq.pop();
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};

