class Solution {
public:
    string reverseVowels(string s) {
        
       
        string s1="";
        
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        
        for(char ch:s){
            if(st.count(ch)==1){
                s1+=ch;
            }
        }
        
        reverse(s1.begin(),s1.end());
        
        int i=0;
        
        for(char &ch:s){
            if(st.count(ch)==1){
                ch=s1[i];
                i++;
            }
        }
        
        return s;
    }
};