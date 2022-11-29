/*
rand ()

The rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX). 

So to get random value from any vector
return v[rand%v.size()];
*/

/*
to check if element already present or not, use unordered map (search O(1))
Note: map and set searches in O(logn)
*/

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
     vector<int>v;
  unordered_map<int,int>mp;
  
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
          return false;
        v.push_back(val);
  /* mp[val]=index of val in vector so that we can trace  the partiucular value in vector using its value present in map*/
      
      mp[val]=v.size()-1;  
      return true;
    }
    
    bool remove(int val) {
      if(mp.find(val)==mp.end())
         return false;
    /*
    Now remove the val from map as well as from vector
 To remove it from vector, put last element of vector to its position and decrease the 
    size of vector, index of val in vector= mp[val] 
    also update value of last element in map
    erase val from map
    */
      v[mp[val]]=v[v.size()-1];
      mp[v[v.size()-1]]=mp[val];
      
      v.pop_back();
      mp.erase(val);
      
      return true;
    }
  
   int getRandom(){
     return v[rand()%v.size()];
   }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */