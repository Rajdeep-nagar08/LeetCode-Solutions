class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n=word.size();
        
        if(n==1)
            return true;
        
        bool f=isupper(word[1]);
        
        for(int i=1;i<n;i++){
            if(isupper(word[i])){
                if((isupper(word[0]) && f)==false)
                    return false;
            }
            else{
               if(f==true)
                   return false;
            }
        }
        
        return true;
        
    }
};