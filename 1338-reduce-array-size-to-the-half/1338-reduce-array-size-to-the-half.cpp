class Solution {
public:
    int minSetSize(vector<int>& arr) {
       
      int n=arr.size();
      int need=n/2;
      
      unordered_map<int,int>mp;
      
      for(int x:arr)
        mp[x]++;
      
       vector<int>freq(mp.size());
      
      for(auto x:mp)
        freq.push_back(x.second);
      
      sort(freq.rbegin(),freq.rend());
      
      
      int count=0;
      int sum=0;
      int i=0;
      while(i<n && sum<need){
        sum+=freq[i];
        count++;
        i++;
      }
      
      return count;
      }
};