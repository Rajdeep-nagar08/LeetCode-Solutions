/*

all characters should have different freq

*/


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        
        for(char ch:s){
            mp[ch]++;
        }
        
        vector<int>v;
        
        for(auto it:mp){
            v.push_back(it.second);
        }
        
        sort(v.rbegin(),v.rend());
        
        int sz=v.size();
        
        int ans=0;
        
        int i=1;
        
        while(i<sz){
            if(v[i]==v[i-1]){
                 ans+=1;
                v[i]--;
            }
            else if(v[i]>v[i-1]){
                if(v[i-1]==0){
                ans+=v[i];
                v[i]=0;
                }
                else{
                    ans+=(v[i]-v[i-1]+1);
                    v[i]=v[i-1]-1;

                }
            }
            
            i++;
        }
        
        return ans;
        
    }
};

