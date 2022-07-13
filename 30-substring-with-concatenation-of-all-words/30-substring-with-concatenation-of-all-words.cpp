class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        
        unordered_map<string,int>hash1;
        
        for(string str:words)
            hash1[str]++;
        
        int words_size=words.size();
        
        int length_word=words[0].length();
        
        int length_words=words_size * length_word;
        
        if(s.length()<length_words)
            return ans;
        
        for(int i=0;i<=s.length() - length_words;i++){
            unordered_map<string,int>hash2(hash1);
            int j=i;
            int count=words_size;
            while(j<i+length_words){
                string str=s.substr(j,length_word);
                if(hash1.find(str)==hash1.end() || hash2[str]==0)
                    break;
                else
                {
                    hash2[str]--;
                    count--;
                    j=j+length_word;
                }
            }
            if(count==0)
                ans.push_back(i);
        }
        return ans;
        
    }
};