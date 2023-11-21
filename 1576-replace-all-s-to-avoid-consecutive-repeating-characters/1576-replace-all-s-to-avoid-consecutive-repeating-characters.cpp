class Solution {
public:
    string modifyString(string s) {
        
        int n=s.size();
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='?')
                continue;
            
            while(true){
                int x=rand()%26;   // [0,25]
                char ch='a'+x;
                if((i>0 and ch==s[i-1]) || (i<n-1 and ch==s[i+1]))
                    continue;
                
                s[i]=ch;
                break;
            }
        }
        
        return s;
    }
};