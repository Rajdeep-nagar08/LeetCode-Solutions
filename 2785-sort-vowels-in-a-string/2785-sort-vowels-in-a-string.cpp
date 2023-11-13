class Solution {
public:
    string sortVowels(string s) {
        
        
        set<char>st={'a','A','e','E','I','i','O','o','U','u'};
        
        string ans;
        
        vector<char>v;
        
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])==1){
                v.push_back(s[i]);
            }
        }
        
        sort(v.begin(),v.end());
        
        
          int j=0;
        
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])==1){
                ans.push_back(v[j]);
                j++;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
        
    }
};