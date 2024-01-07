class Solution {
public:
    string minWindow(string s, string t) {
        
        // minimum window substring
        
        
        int n=s.size();
        
        
        unordered_map<char,int>mp;
        
        for(char ch:t){
            mp[ch]++;
        }
        
        int cnt=mp.size();
        
        // cout<<cnt<<endl;
        
        int i=0, j=0;
        
        string ans;
        
        while(i<n){
            
            if(mp.count(s[i])){
                mp[s[i]]--;
            }
            
            if(mp.count(s[i]) and mp[s[i]]==0){
                cnt--;
            }
            
            // cout<<i<<" "<<cnt<<endl;
            
            if(cnt==0){
                // compress the window from back
                
//                 for(auto it:mp){
//                     cout<<it.first<<" "<<it.second<<endl;
//                 }
                
                while((mp.count(s[j])==0) || (mp.count(s[j]) and mp[s[j]]<0)){
                    if(mp.count(s[j]))
                     mp[s[j]]++;
                    j++;
                }
                
                if(ans.size()==0 || ans.size()>(i-j+1)){
                    ans=s.substr(j,i-j+1);
                }
                
            }
            
            i++;
            
        }
        
        
        return ans;
    }
};