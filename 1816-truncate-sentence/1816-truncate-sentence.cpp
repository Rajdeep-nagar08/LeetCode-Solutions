class Solution {
public:
    string truncateSentence(string str, int k) {

stringstream ss(str);
string word;
int count=0;
        string ans="";
while(ss>>word){
ans+=word;
count++;
    if(count<k)
        ans+=" ";
    else
        break;
    
}
        
        
        return ans;


    }
};