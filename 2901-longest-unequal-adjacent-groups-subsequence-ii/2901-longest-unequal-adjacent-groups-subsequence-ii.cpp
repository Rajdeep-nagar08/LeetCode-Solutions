
class Solution {
public:
    
    
    unordered_map<int, vector<string>>dp;   // dp[i] longest subseq. for [i...n-1]
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
       
  
        for(int i=0;i<n;i++){
            dp[i].push_back(words[i]);
        }
        
        
        // j    i
        
        int maxLen=1;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                if(words[j].size()==words[i].size() && groups[j]!=groups[i] && hmd(words[j],words[i])){
                    
                    
                    if(dp[j].size()+1 > dp[i].size()){
                        
                        dp[i]= dp[j];
                        
                        dp[i].push_back(words[i]);
                        
                        maxLen=max(maxLen, (int)dp[i].size());
                        
                    }
                    
                    
                }
                
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(dp[i].size()==maxLen)
                return dp[i];
        }
        
        
        return {};
        
     

    }
    
    
    bool hmd(string& a,  string& b) {
            int dist = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) {
                    dist++;
                }
            }
            return dist==1;
        }
    
};