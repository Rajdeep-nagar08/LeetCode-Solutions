class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int count=0;
        
        int n=s.size();
        
        int i=0;
        
        while(i<=n-2){
            if(s[i]!=s[i+1]){
                int i1=i;
                int j1=i+1;
                while(i1>=0 && j1<n && (s[i1]==s[i]) && (s[j1]==s[i+1])){
                    count++;
                    i1--,j1++;
                }
                i=j1-1;
            }
            else
                i++;
        }
        
        return count;
        
    }
};