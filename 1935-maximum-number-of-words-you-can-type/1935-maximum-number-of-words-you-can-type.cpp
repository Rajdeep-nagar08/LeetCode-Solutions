class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        
        int count=0;
stringstream ss(text);
string word;
while(ss>>word){
    
    bool flag=true;
    for(char ch1:word){
        for(char ch2:broken){
            if(ch1==ch2){
                flag=false;
                break;
            }
        }
    }
    
    if(flag)
        count++;
}
        
     return count;   
        
    }
};