class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        
        int n=words.size();
        
        unordered_map<char,int>mp;
        
        for(string str:words){
            for(char ch:str){
                mp[ch]++;
            }
        }
        
        for(auto it:mp){
            if(it.second%n !=0)
                return false;
        }
        
        return true;
        
    }
};