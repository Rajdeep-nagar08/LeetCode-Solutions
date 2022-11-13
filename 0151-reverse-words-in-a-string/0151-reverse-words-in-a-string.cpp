class Solution {
public:
    string reverseWords(string s) {
    
        
        reverse(s.begin(),s.end());
        
        
stringstream ss(s); 
string temp;
string str="";
while(ss>>temp){
    str+=" ";
    reverse(temp.begin(),temp.end());
str+=temp;
}
        
        return str.substr(1);
    }
};