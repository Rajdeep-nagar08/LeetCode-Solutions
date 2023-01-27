class Solution {
public:
    set<string> dict;
    bool check(string &word,int c)
    {
        if(word.size()==0)
        {
            // cout<<c<<endl;
            if(c>=2)
            return true;
            
            return false;
        }

        for(int i=1;i<=word.size();i++)
        {
            string left=word.substr(0,i);
            string right=word.substr(i);
            if(dict.find(left)!=dict.end())
            {
                ++c;
                if(check(right,c))
                {
                    return true;
                }
                --c;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto &word:words)
        {
            dict.insert(word);
        }
        for(auto &word:words)
        {
            if(check(word,0))
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
