class Solution {
public:
    string frequencySort(string s) {
        
      priority_queue<pair<int,char>>pq;
      map<char,int>mp;
      for(char c:s)
        mp[c]++;
      
      for(auto it:mp)
        pq.push({it.second,it.first});
    
      
      string ans="";
      
      while(pq.size()>0){
        string temp(pq.top().first,pq.top().second);
        ans=ans+temp;
        pq.pop();
      }
      
      return ans;
    }  
};