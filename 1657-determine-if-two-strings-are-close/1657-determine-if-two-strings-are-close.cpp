class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n!=m)
            return false;
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1==word2)
            return true;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(char c:word1)
            v1[c-'a']++;
        for(char c:word2)
            v2[c-'a']++;
        for(int i=0;i<26;i++){
            if((v1[i]>0 && v2[i]==0) ||  (v1[i]==0 && v2[i]>0))
                return false;
        }
        sort(v1.begin(),v1.end());
         sort(v2.begin(),v2.end());
        for(int i=0;i<26;i++){
          if(v1[i]!=v2[i])
              return false;
        }
        
    return true;
    }
};