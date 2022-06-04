#define lln long long int
class Solution {
public:
    long long countVowels(string word) {
        
        lln ans=0;
        int n=word.size();
        set<char>st={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            lln l=i;
            lln r=(n-1-i);
            
            if(st.count(word[i])==1){
                ans+=1ll*(l+1)*(r+1);
            }
            
        }
        
        return ans;
    }
};