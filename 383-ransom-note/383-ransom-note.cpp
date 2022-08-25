class Solution {
public:
    bool canConstruct(string ran, string mag) {
        
      vector<int>v(26,0);
        
        for(char ch:mag){
            v[ch-'a']++;
        }
        
        for(char ch:ran){
            if(v[ch-'a']==0)
                return false;
            v[ch-'a']--;
        }
        
        return true;
        
    }
};