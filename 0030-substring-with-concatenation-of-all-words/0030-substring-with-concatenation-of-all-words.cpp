/*
-> make a window of size=words.size()*words[0].size() 

->check if window is valid?
        ->true: push start of window
        ->false: continue;
*/
class Solution {
public:
    bool check(string &s,unordered_map<string,int> store,int wordLen){
        for(int i=0;i<s.size();i+=wordLen){
            string str=s.substr(i,wordLen);
            
            if(store.find(str)==store.end()) 
                return false;
            
            store[str]--;
            
            if(store[str]==-1 ) 
                return false;
            
        }
        return true;
    
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int windowSize=words.size()*words[0].size();
        
        unordered_map<string,int> store;
        
        for(int i=0;i<words.size();i++){
            store[words[i]]++;
        }
        
        int start=0;
        while(start+windowSize<=s.size()){
            string s1=s.substr(start,windowSize);
            if(check(s1,store,words[0].size())) ans.push_back(start);
            
            start++;
        }
        
        return ans;
    }
};