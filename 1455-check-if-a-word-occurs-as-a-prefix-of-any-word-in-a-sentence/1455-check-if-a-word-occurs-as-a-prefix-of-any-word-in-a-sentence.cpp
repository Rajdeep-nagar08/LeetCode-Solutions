class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
   
        int l=search.size();
stringstream ss(sentence);
string word;
int count=0;
while(ss>>word){

count++;
    
if(word.size()<l)
    continue;
    
string s1=word.substr(0,l);
    
    if(s1==search)
        return count;
    
}
        
        return -1;

    }
};