class Solution {
public:
    string toLowerCase(string s) {
        
        for(char &ch:s){
            if(isupper(ch)){
                ch=tolower(ch);
            }
        }
        return s;
    }
};