/*
Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

 Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. So add {i,mp[left]} to ans 2) same for checking the right side of current word: candidate | left | right , add {mp[right],i}
 
 Edge case:-
 if there exist a empty string:-
 When left is empty and right is a palindrome, apart from {i, mp[left]}, we can also add {mp[left], i} to result so that no valid pair is missing.
*/


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
    
      unordered_map<string,int>mp;
      for(int i=0;i<words.size();i++){
        string s=words[i];
        reverse(s.begin(),s.end());
        mp[s]=i;
      }
      vector<vector<int>>ans;
      
      for(int i=0;i<words.size();i++){
        for(int j=1;j<=(int)words[i].length();j++){
          string left=words[i].substr(0,j);
          string right=words[i].substr(j,(int)words[i].length()-j);
          
          if(mp.find(left)!=mp.end() && ispalind(right) && mp[left]!=i){
            ans.push_back({i,mp[left]});
            if(left.size()==0)
              ans.push_back({mp[left],i});
          }
          if(mp.find(right)!=mp.end() && ispalind(left) && mp[right]!=i){
            ans.push_back({mp[right],i});
            if(right.size()==0)
              ans.push_back({i,mp[right]});
          }
        }
      }
      return ans;
    }
  
   bool ispalind(string &s){
     int l=0;
     int r=(int)s.length()-1;
     while(l<=r){
       if(s[l]!=s[r])
         return false;
       l++;
       r--;
     }
     return true;
   }
};


