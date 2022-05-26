class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int n=s.size();
        
        string ans="";
        
        unordered_map<int,char>mp;
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])==false){
                mp[i]=s[i];
            }
        }
        
        int j=n-1;
        
        int i=0;
        
        while(j>=0){
            if(mp.count(i)==1){
                ans.push_back(mp[i]);
                i++;
            }
            else if(isalpha(s[j])){
                ans.push_back(s[j]);
                j--;
                i++;
            }
            else{
                j--;
            }
        }
        
        if(ans.size()<s.size()){
            while(mp.count(i)==1){
                ans.push_back(mp[i]);
                i++; 
            }
        }
        
        
        return ans;
    }
};