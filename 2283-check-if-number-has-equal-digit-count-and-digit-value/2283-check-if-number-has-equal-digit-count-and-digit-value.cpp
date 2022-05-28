class Solution {
public:
    bool digitCount(string num) {
        
        
        unordered_map<int,int>mp;
        
        for(char ch:num){
            mp[ch-'0']++;
        }
        
       for(int i=0;i<num.size();i++){
           int c=num[i]-'0';
           if(mp.count(i)==1){
               if(mp[i]!=c)
               return false;
           }
           else{
               if(c!=0)
                   return false;
           }
       }
        
        return true;
    }
};