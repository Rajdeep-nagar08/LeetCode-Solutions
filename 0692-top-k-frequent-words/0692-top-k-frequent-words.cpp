class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        
        for(string &str:words)
            mp[str]++;
        
priority_queue<pair<int,string>, vector<pair<int,string>>,comp>pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string>ans;
        
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
    
        reverse(ans.begin(),ans.end());
        
        return ans;
            
    }
    
private:
    
    struct comp{
        
    bool operator ()(const pair<int,string>&p1,const pair<int,string>&p2){
        if(p1.first!=p2.first)
            return p1.first>p2.first;
        else
            return p1.second<p2.second;
       }
    };
};