class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>ms;
        unordered_map<char,int>mt;
        
        for(char ch:t)
            mt[ch]++;
        
        int i=0,j=0;
        
        int idx=-1;
        int len=INT_MAX;
        string ans="";
        
        int count=0;
        
        while(i<s.length()){
            ms[s[i]]++;
            
            if(ms[s[i]]<=mt[s[i]])  // increase count whenever matched any char
                count++;
            
            if(count==t.length()){  // valid window found , now decrease size of window
                
                while((ms[s[j]] > mt[s[j]]) || (mt[s[j]]==0)){
                    if(ms[s[j]]>mt[s[j]])
                        ms[s[j]]--;
                    
                     j++;
                }
                      
                    if(i-j+1 < len){
                        len=i-j+1;
                        ans=s.substr(j,len);
                    }
                }
            
                i++;
                
        }
                      
        return ans;
    }
};