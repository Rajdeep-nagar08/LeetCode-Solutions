class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        
      unordered_set<string>st;
      for(auto s:strs)
        st.insert(s);
      
      int count=0;
      for(int i=0;i<strs.size();i++){
        if(st.find(strs[i])!=st.end()){
          dfs(strs[i],strs,st);
          count++;
        }
      }
      return count;
    }
  
     void dfs(string s,vector<string>&strs,unordered_set<string>&st){
       st.erase(s);
       
       for(int i=0;i<s.length()-1;i++){
         for(int j=i+1;j<s.length();j++){
           swap(s[i],s[j]);
           if(st.find(s)!=st.end())
             dfs(s,strs,st);
           swap(s[i],s[j]);
         }
       }
     }
};