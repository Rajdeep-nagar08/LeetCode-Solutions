

#define lln long long int
class Solution {
public:
    int longestSubsequence(string s, int k) {
        
     lln no=0;
        
     int idx=0;
        
     int count=0;
        
        int i;
        
     for(i=s.length()-1;i>=0;i--){
         if(s[i]=='0'){
             idx++;
             count++;
         }
         else{
             if(idx>32)
                 break;
             no=no|(1ll*1<<idx);
             idx++;
             count++;
             if(no>k){
                 count--;
                 break;
             }
         }
     }
        
        i--;
        
        while(i>=0){
            if(s[i]=='0')
                count++;
            
            i--;
        }
      
        return count;
    }
};