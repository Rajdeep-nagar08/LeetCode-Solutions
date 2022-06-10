class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=(int)s.length();
        if(l==0)
            return 0;
        int i=0;
        int j=0;
        int len=0;
        int mx=INT_MIN;
        map<char,int>mp;
        while(j<l){ 
            mp[s[j]]++;
            if(mp[s[j]]==1){
                len=j-i+1;
                mx=max(mx,len);
            }
            else if(mp[s[j]]>1){
                while(mp[s[j]]!=1){
                    mp[s[i]]--;
                    i++;
                }
       len=j-i+1;
                mx=max(mx,len);
            }
 j++;
    
        }
        return mx;
    }
};