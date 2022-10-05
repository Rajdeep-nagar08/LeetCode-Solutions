class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      
        
        int n=words.size();
        
        
        vector<int>v(26,0);
        
        for(char ch:chars){
            v[ch-'a']++;
        }
        
        int ans=0;
        
        for(string str:words){
            
            vector<int>v1(v);
            
            bool flag=true;
            
            for(char ch:str){
                if(v1[ch-'a']==0){
                    flag=false;
                    break;
                }
                v1[ch-'a']--;
                
            }
            
            if(flag)
                ans+=(int)str.size();
        }
        
        return ans;
    }
};