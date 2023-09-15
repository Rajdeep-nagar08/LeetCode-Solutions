   /*
        
         if all chars of words[i] are available then we have choices either we build it or not
         
         letters.length = 100
         
         while we form any words[i] we needs to remove all its chars from letters
         
         if we use dp, then how we keep trace of each occurence of chars currently we have in letters ?
         
         dp[i][map to keep trace the occurence of each chars of letters] = max score we can form using [i....n-1]
        
        */
        

class Solution {
public:
    
    int n;
    
    unordered_map<int,map<map<char,int>,int>>dp;
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        n=words.size();
        
        map<char,int>mp;
        
        for(char ch :letters){
            mp[ch]++;
        }
        
        return find(0,mp,words, score);
        
    }
    
    int find(int i, map<char,int>&mp, vector<string>&words, vector<int>&score){
            if(i>=n)
                return 0;
            
            if(dp[i].count(mp)==1)
                return dp[i][mp];
        
        
          int sc1=0, sc2=0;
        
        
          sc1=find(i+1,mp,words,score);
        
          bool valid=true;
        
          map<char,int>mp1(mp);
        
          for(char ch:words[i]){
              if(mp1[ch]==0)
              {
                  valid=false;
                  break;
              }
              mp1[ch]--;
          }
        
        if(valid){
            int get=0;
            
            for(char ch:words[i]){
                get+=score[ch-'a'];
                mp[ch]--;
            }
            
            sc2=get+find(i+1,mp,words,score);
            
             for(char ch:words[i]){
                mp[ch]++;
            }
            
            
        }
        
        return dp[i][mp]=max(sc1,sc2);
        
    }
};