/*
All the timestamps timestamp of set are strictly increasing.
So to get a value of perticular key and timestamp , we can do binary search for timestamp

Note: upper bound can be apply either on map or vector ( not on unordered map)
*/
/*
class TimeMap {
  unordered_map<string,map<int,string>>mp;  // key->{timestamp,value}
  // instead of inside map, we can also use vector of pair ( becouse timestamp wiil already stored in sorted order as per the qusetion)
  
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
  
  Imagine we have the following timestamps: [5, 10, 15].

If we query, say, 20, upper_bound returns end(), so the result is the label for 15 (prev(end())).
Now, if we query 3, upper_bound returns begin(), and that means we do not have a label (the result is an empty string).

let we were given 7, upper_bound will give 10 and prev(10)=5 , which is the ans for 7


Another interesting case is when we query the exact timestamp, say, 10. upper_bound will return 15 and prev(15)

Note: we can also use lower bound : in that case we need to take care of equality also

    
  
    string get(string key, int timestamp) {
        
      auto it= mp[key].upper_bound(timestamp);
      
      if(it==mp[key].begin())
        return "";
      
      it--;
      
      return it->second;
    }
};
*/

class TimeMap {
   unordered_map<string,vector<pair<int,string>>>mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      mp[key].push_back({timestamp,value});
    }

string get(string key,int timestamp) {
  
  auto it= upper_bound(mp[key].begin(),mp[key].end(),pair<int,string>{timestamp,""},
                      [](const pair<int,string>&p1 , const pair<int,string>&p2 ){
                         return p1.first<p2.first;
                      });
 
  
  if(it==mp[key].begin())
    return "";
  
  it--;
  
  return it->second;
}
  
};


