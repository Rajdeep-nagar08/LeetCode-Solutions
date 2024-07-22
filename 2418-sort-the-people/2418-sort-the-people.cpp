class Solution {
public:
    vector<string> sortPeople(vector<string>& nam, vector<int>& ht) {
        
        vector<string>ans;
        
        vector<pair<int,string>>v;
        
        int n=nam.size();
        
        for(int i=0;i<n;i++){
            v.push_back({ht[i],nam[i]});
        }
        
        sort(v.rbegin(),v.rend());
        
        for(auto it:v){
            ans.push_back(it.second);
            
        }
            return ans;
        
    }
};