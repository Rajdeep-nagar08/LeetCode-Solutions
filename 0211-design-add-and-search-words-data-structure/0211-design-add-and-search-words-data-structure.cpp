unordered_map<string,int>mp; //to keep track of strings directly (helps for non doted strings)

unordered_map<int, vector<string>>mp1;

//this map help us when there is any doted string, we can directly check char by char all those strings whose length matched with the search string 


class WordDictionary {
public:
    WordDictionary() {
        mp.clear();
        mp1.clear();
    }
    
    void addWord(string word) {
        mp[word]=word.length();
        mp1[word.length()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.count(word)==1)
            return true;
        
         int dot=0;
        for(char ch: word){
            if(ch=='.'){
                dot++;
                break;
            }
        }
        
        if(dot==0)
            return false;
        
        for(auto it:mp1[word.length()]){
        
                string str=it;
                int i=0;
                while(i<word.length()){
                    if(word[i]=='.'){
                        i++;
                        continue;
                    }
                    if(word[i]!=str[i])
                        break;
                    i++;
                }
                if(i==word.length())
                    return true;
            }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */