 /*
        First, we save the occurance of each char in s by using vector<int> hash(128,0)
        2. we make a ans string
        3. traverse the string again, each time we see a char, we decrease the occurance in the hash, and check if this char has been in the ans or not, if so, skip the char
        while the result.back() is larger than current char, we check if we can still see this ans.back() in the latter substring. if we can still find it later, we can pop it from the back and add it back later
        4. add current char to the back of the ans string
        5. set visited[current char]=true
        */
        

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
     
      vector<int>hash(256,0);
      for(char ch:s)
        hash[ch]++;
      
      vector<bool>vis(256,false);
      
      string ans="";
      for(int i=0;i<n;i++){
        hash[s[i]]--;
        if(vis[s[i]]==true)
          continue;
        while(ans.size()>0 && ans.back()>s[i] && hash[ans.back()]>0){
          vis[ans.back()]=false;
          ans.pop_back();
        }
        ans=ans+s[i];
        vis[s[i]]=true;
      }
      return ans;
    }
};