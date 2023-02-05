/*
fixed size sliding window
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;
        
        int n=s.length();
        int m=p.length();
        if(m>n)
            return {};
        
        unordered_map<char,int>mp;
        for(char ch:p)
            mp[ch]++;
        
        int count=mp.size();
        int i=0,j=0;
        
        while(i<m){
            if(mp.count(s[i])){
                mp[s[i]]--;
            if(mp[s[i]]==0)
                count--;
            }
            i++;
        }
        if(count==0)
            ans.push_back(0);
        
        while(i<n){
            if(mp.count(s[j])==1){
                mp[s[j]]++;
                if(mp[s[j]]==1)
                    count++;
            }
            j++;
            if(mp.count(s[i])==1){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    count--;
        
            }
            i++;
            if(count==0)
                ans.push_back(j);
            
        }
        
        return ans;
            
    }
};