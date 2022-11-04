class Solution {
public:
    int countPalindromicSubsequence(string s) {
     
        
        int n=s.size();
            
        vector<vector<int>>left(n);
        
        vector<int>v1(26,0);
     
        vector<vector<int>>right(n);
        
        vector<int>v2(26,0);
        
        
        for(int i=0;i<n;i++){
            v1[s[i]-'a']++;
            v2[s[n-1-i]-'a']++;
            left[i]=v1;
            right[n-1-i]=v2;
        }
        
        int ans=0;
        
      //  unordered_map<string,int>mp;
        
        unordered_map<char,unordered_map<char,int>>mp;
                
        for(int i=1;i<n-1;i++){
            for(int j=0;j<26;j++){
    if(left[i-1][j]>0 && right[i+1][j]>0 && (mp['a'+j][s[i]]==0)){
                  ans++;
                 mp['a'+j][s[i]]++;
                }
            }
        }
        
        return ans;
    }
};