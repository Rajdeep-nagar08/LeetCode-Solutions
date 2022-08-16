class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int>v(26,0);
        
        for(int i=0;i<s.size();i++){
            int no=s[i]-'a';
            
            v[no]++;
        }
        
         for(int i=0;i<s.size();i++){
            int no=s[i]-'a';
            if(v[no]==1)
             return i;
        }
        
        
        
        return -1;
    }
};