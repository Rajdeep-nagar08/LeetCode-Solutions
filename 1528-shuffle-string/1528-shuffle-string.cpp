class Solution {
public:
    
     string restoreString(string s, vector<int>& indcs) {
        
        int n=s.size();
         
         string s1=s;
         
         for(int i=0;i<n;i++){
             s1[indcs[i]]=s[i];
         }
         
         return s1;
         
    }
};