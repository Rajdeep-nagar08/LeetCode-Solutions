class Solution {
public:
    int partitionString(string s) {
        
        
        int n=s.size();
        
        int ans=0;
        
        unordered_map<char,int>mp;
        
        for(char ch:s){
            if(mp[ch]>0){
                mp.clear();
                mp[ch]++;
                ans++;
            }
            else
                mp[ch]++;
        }
        return ans+1;
        
    }
};