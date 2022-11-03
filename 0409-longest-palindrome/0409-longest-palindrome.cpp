class Solution {
public:
    int longestPalindrome(string s) {
        
        
        int n=s.size();
        
        unordered_map<char,int>mp;
        
        for(char ch:s){
            mp[ch]++;
        }
        
        int ans=0;
        
        int odd=0;
        
        for(auto it:mp){
            char ch=it.first;
            int cnt=it.second;
            if(cnt%2==0)
                ans+=cnt;
            else{
               ans+=(cnt-1);
                odd++;
            }
        }
        
        if(odd>0)
            ans++;
        
        return ans;
    }
};