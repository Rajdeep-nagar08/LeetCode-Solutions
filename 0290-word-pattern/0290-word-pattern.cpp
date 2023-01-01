class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char>mp;
        set<char>st;
        int i=0,j=0;
        while(i<pattern.length() && j<s.length()){
            string str="";
            while(s[j]!=' ' && j<s.length()){
                str+=s[j];
                j++;
            }
          
               j++;
            
            if(mp.count(str)==1){
                if(mp[str]!=pattern[i])
                    return false;
            }
            else if(st.find(pattern[i])==st.end()){
                mp[str]=pattern[i];
                st.insert(pattern[i]);
            }
            else
                return false;
            
        
               i++;
        }
        if(i==pattern.length() && j==s.length()+1)
        return true;
        
        return false;
    }
};