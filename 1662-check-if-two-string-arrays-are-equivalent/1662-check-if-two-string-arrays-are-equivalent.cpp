class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        
     
        
        string str1="",str2="";
        for(string s:w1)
            str1+=s;
        for(string s:w2)
            str2+=s;
        
        return str1==str2;
    }
};