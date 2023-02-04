class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
      map<char,int>mp;
      for(char c:s1)
        mp[c]++;
      
      int count=mp.size();
      
      int i=0,j=0;
    int n=s1.length();
    int m=s2.length();
      if(n>m)
        return false;
      
      while(i<n){
        mp[s2[i]]--;
        if(mp[s2[i]]==0)
          count--;
        i++;
      }
        if(count==0)
          return true;
      
      while(i<s2.length()){
        if(mp.count(s2[j])==1){
          if(mp[s2[j]]==0){
            mp[s2[j]]++;
            count++;
          }
          else
            mp[s2[j]]++;
        }
        
        if(mp.count(s2[i])==1){
          mp[s2[i]]--;
          if(mp[s2[i]]==0)
            count--;
        }
        if(count==0)
          return true;
        i++;
        j++;
      }
      return false;
    }
};