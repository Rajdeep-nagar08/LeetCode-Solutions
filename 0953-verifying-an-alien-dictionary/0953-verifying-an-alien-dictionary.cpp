class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        
        int n=words.size();
        
        int m=order.size();
        
        unordered_map<char,char>mp;
        
        for(int i=0;i<26;i++){
            mp[order[i]]='a'+i;
        }
        
        vector<pair<string,int>>v;
        
        for(int i=0;i<n;i++){
            for(char &ch:words[i]){
                ch=mp[ch];
            }
            v.push_back({words[i],i});
        }
        
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++){
            if(v[i].second!=i)
                return false;
        }
        
        return true;
    }
};