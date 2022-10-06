class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>>mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
       mp[key].push_back({timestamp,value}); // foo => {1,bar} , {4,bar2}
        
    }
    
    string get(string key, int timestamp) {
                        
        if(mp[key].size()==0)
            return "";
        
pair<int,string>p= {timestamp,"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"};
        
        int i=upper_bound(mp[key].begin(),mp[key].end(),p)-mp[key].begin();
         
       i--;
        
        if(i<0)
            return "";
        
        return mp[key][i].second;
        
    }
};
