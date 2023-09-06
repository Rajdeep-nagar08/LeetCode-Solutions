/*
Binary Search Using upper_bound and lower bound (For sorted array):-
5 5 5 6 6 6 7 7
auto lower = lower_bound(v.begin(), v.end(), 6); -> index =3 (greater or equal to 6)
auto upper = upper_bound(v.begin(), v.end(), 6);  -> index=6  (greater then 6)

So no of 6 present in the array= upper - lower= 6-3=3
*/

/*
For this problem , store all no's in unordered_map as (no- index), as there are duplicate no's
so use unordered_map<int,vector<int>>mp

then for any range [left,right] , traverse the map (if size of vector >= threshold, then
No of no's present in the index range [left,right] = [lower bound of left index]-[upper bound of right index])

*/



//IT Shows TLE:-
/*
class MajorityChecker {
  unordered_map<int,vector<int>>mp;
public:
  
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
          mp[arr[i]].push_back(i);
        
    }
    
    int query(int left, int right, int threshold) {
      
       for(auto x:mp){
         if(x.second.size()<threshold)
           continue;
         
         auto i1=lower_bound(x.second.begin(),x.second.end(),left);
         auto i2=upper_bound(x.second.begin(),x.second.end(),right);
            if((i2-i1) >=threshold)
              return x.first;
       }
      return -1;
    }
};
*/

/* For more optimisation, we sort the no's by there frquency(in decreasing order of size of vector size inside map) then traverse, so that we can reach to majority element soon

It also show TLE

class MajorityChecker {
  unordered_map<int,vector<int>>mp;
  vector<pair<int,vector<int>>>v;
public:
  
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
          mp[arr[i]].push_back(i);
      
      for(auto x: mp)
        v.push_back({x.first,x.second});
      // INLINE SORTING
sort(v.begin(),v.end(),[](auto &p1, auto &p2) { return p1.second.size() > p2.second.size();});
      
    }
    
    int query(int left, int right, int threshold) {
      
       for(auto x:v){
         if(x.second.size()<threshold)
           continue;
         
         auto i1=lower_bound(x.second.begin(),x.second.end(),left);
         auto i2=upper_bound(x.second.begin(),x.second.end(),right);
            if((i2-i1) >=threshold)
              return x.first;
       }
      return -1;
    }
};
*/

/*
Another way to narrow down the list of potential candidates is to look at the queried range and randomly pick an element. If there is a majority element, there is more than 50% chance of picking that element. So, we can just do a few picks (say, 10) and do the majority check for those picks only.
*/

class MajorityChecker {
  vector<int>v;
  unordered_map<int,vector<int>>mp;
public:
  
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
          mp[arr[i]].push_back(i);
        
      v=arr;
    }
    
    int query(int left, int right, int threshold) {
      
       for(int k=0;k<10;k++){
        
//          int random_no = v[left+ rand()%(right-left+1)];
//          auto x= mp[random_no];
         
//          if(x.size()<threshold)
//            continue;
         
//          auto i1=lower_bound(x.begin(),x.end(),left);
//          auto i2=upper_bound(x.begin(),x.end(),right);
//             if((i2-i1) >=threshold)
//               return random_no;
             
          auto i = mp.find(v[left + rand() % (right - left + 1)]);
    if (i->second.size() < threshold) continue;
    if (upper_bound(begin(i->second), end(i->second), right) - 
        lower_bound(begin(i->second), end(i->second), left) >= threshold) return i->first;
  
         
       }
      return -1;
    }
};