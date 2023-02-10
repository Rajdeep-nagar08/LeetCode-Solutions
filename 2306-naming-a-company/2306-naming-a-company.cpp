#define lln long long int


class Solution {
public:
    
    int n;
    
    long long distinctNames(vector<string>& ideas) {
    
        n=ideas.size();
        
        unordered_map<string,int>mp1;
        
        for(string str:ideas){
            mp1[str]++;
        }
        
        unordered_map<char,unordered_map<char,int>>mp;
        
        for(string str:ideas){
            
            for(char ch='a';ch<='z';ch++){
                string s=str;
                s[0]=ch;
                if(ch!=str[0] && (mp1.count(s)!=1)){
                    mp[str[0]][ch]++;
                }
            }
        }

        
        lln ans=0;
        
        for(auto it:mp){
            
            char ch=it.first;  // start char
                        
            for(auto it1:it.second){  // can be replaced by it1.first
               
                char ch1=it1.first;
                
                int no1=it1.second;
                
                if(mp.count(ch1)){
                int no2=mp[ch1][ch];
                
                
                ans+=no1*no2;
                }
            }
            
        }
        
        return ans;
    }
};